//#pragma save_binary

// This is a race body for Elf, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "elf");

	// Elf has little special defense.
	body->set("special_defense", ([ "fire": -13, "cold": -5, "acid": -5,
		"poison": -12, "mental": 35, "electric": -5, "energy": -5,
		"magic": 10, "evil": -15, "divine": 5, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 25);

	// the natural age of Elf.
	if( userp(body) ) body->set("natural_age", 100);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 12,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body,  8,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 4);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s对准%s一记直拳", "%s猛踹%s一腿",
		"%s挥拳攻击%s", "%s伸手抓向%s", }) );
	body->set_c_limbs( ({ "门面", "左臂", "右臂", "前胸", "左腿", "右腿",
		"脖子", "左肩", "右肩", "後心", "小腹", }) );
*/
	// Elf has weapon class bonus.
	body->set("natural_weapon_class1", "@@query_elf_WC_bonus");
        // the special commands for user elf.
        add_action("do_invisible", "invisible");
        add_action("do_visible", "visible");
}

// These functions are used for race Elf.
// Please don't cover the functions in user.c.

int do_invisible(string arg)
{
        object ob;
        if( this_player()->query_attacker())
          {  this_player()->block_attack(2) ;
             return notify_fail(" ( 你正在战斗中, 无法集中精神隐形。 )\n") ;
          }
         if( ob= this_player()->query_temp("mounting") )
                return notify_fail(
                    "你正骑在一" + ob->query("unit") + ob->query("c_name")+"上，无法隐形。\n");

        if( this_object()->query("player_invisible") )
                return notify_fail("你已经隐形了。\n");
        this_player()->set("player_invisible",1);
        tell_room( environment(this_object()),
                sprintf("%s的身影渐渐的淡去，从你的面前消失。\n",
                this_object()->query("c_name")),
                this_object() );
        write( "你屏气凝神，开始隐形.\n" );
        return 1;
}
int do_visible(string arg)
{
        if( !this_object()->query("player_invisible") )
                return notify_fail("你现在并没有隐形。\n");
        this_object()->set("player_invisible", 0);
        tell_room( environment(this_object()),
                sprintf("你的前方一阵波动，%s的身影突然浮现出来。\n"
                        ,this_object()->query("c_name")),
                this_object() );
        write( "你放松心神，停止隐形.\n" );
        return 1;
}

int query_natural_life() { return 600; }

// define the cost of advance stats for Elf.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 130, "int":  70, "dex":  80,
		"con": 120, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 130, "int":  70, "dex":  80,
		"con": 120, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat) > 3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return stat_exp_rate[stat];
}

// The block_wield() and block_wear() is to check wheather if the player
// can wield a weapon or wear an armor. If the player is not allowed to
// equip the weapon or armor, return 1 to stop.
int block_wield(object obj)
{
	return 0;
}

int block_wear(object obj)
{
	string *allow_types = ({ "body", "head", "arms", "hands", "legs",
		"feet", "shield", "cloak", "misc","finger" });

	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}

// This function checks if this race can mount other animals.
int valid_mount(object ob)
{
	return (int)ob->query("mounted");
}

int query_elf_WC_bonus()
{
	object weap, ob;
	string type;

	ob = this_object();
	weap = ob->query("weapon1");
	if( !weap ) return 0;
	type = (string)weap->query("type");
	// About 15% primary weapon class bonus when level 19;
	if( type=="longblade" || type=="shortblade" )
		return (int)weap->query("weapon_class") * (int)ob->query_level()  / 120;
}
