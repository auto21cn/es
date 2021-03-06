//#pragma save_binary

// This is a race body for Vampire, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "vampire");

	// Vampire is afraid of divine power and defend evil power.
	body->set("special_defense", ([ 
		"evil": 50, "divine": -50, ]) );

	// effect the critical medication resistance.
	if( userp(body) ) body->set("constitution", 32);

	// the natural age of Vampire.
	if( userp(body) ) body->set("natural_age", 18);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body,  8,  1);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body,  8,  1);
	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30,  5);
	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 8);

	// These variables are used for /adm/daemons/combat_d.c
/*
	body->set_c_verbs( ({ "%s对准%s一记直拳", "%s猛踹%s一腿",
		"%s挥拳攻击%s", "%s伸手抓向%s", }) );
	body->set_c_limbs( ({ "门面", "左臂", "右臂", "前胸", "左腿", "右腿",
		"脖子", "左肩", "右肩", "後心", "小腹", }) );
*/
	// The extra command for vampire.
	add_action( "do_bloodsuck", "bloodsuck" );
}

// These functions are used for race Vampire.
// Please don't cover the functions in user.c.

int query_natural_life() { return 70; }

// define the cost of advance stats for Vampire.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str":  80, "int":  60, "dex":  80,
		"con": 140, "pie": 120, "kar": 120,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str":  80, "int":  60, "dex":  80,
		"con": 140, "pie": 120, "kar": 120,
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

int do_bloodsuck(string arg)
{
	object me, dest;

	if( !arg || arg == "" ) 
		return notify_fail("你要吸谁的血？\n");

	me = this_player();
	dest = present( arg, environment(me) );
	if( !dest || !living(dest) )
		return notify_fail("这里没有这种生物。\n");

	if( dest->query("no_attack") )
		return notify_fail("你不能吸这家伙的血。\n");

        if ( userp(dest) && ((int)dest->query_level()<5) )
                return notify_fail("你不能欺负低等级玩家 !!\n");
	if ( userp(dest) && ((int)me->query_level()<5) )
		return notify_fail("翅膀都还没长硬,就想PK人?\n");
	
	if( dest->query_temp("be_sucked"))
		return notify_fail("这家伙根本不让你靠近，你没有机会吸血。\n");

	if( userp(me) && me->query_temp("bloodsuck") )
		return notify_fail("嘿! 吃太饱不好哦..总要消化一下吧。\n");

	write(sprintf("你张嘴往%s的脖子咬去，",
			dest->query("c_name")));

	tell_room( environment(me), 
		sprintf("%s突然张嘴咬向%s的脖子，", 
			me->query("c_name"), dest->query("c_name")) ,
		({ me, dest }) );

	tell_object( dest, 
		sprintf("%s突然张嘴咬向你的脖子，",
			me->query("c_name")));

	dest->set_temp("be_sucked",1);

	dest->kill_ob( me );
	me->kill_ob( dest );

        me->block_attack(4);

	if ( random((int)me->query_level()*2) < (int)dest->query_level() ) {
		tell_room(environment(me),set_color("但是被发现了 !!\n","HIY"),({}));
		me->set_temp("msg_stop_attack","(你现在手忙脚乱，无法攻击 ！)\n");
		return 1;
	}

	tell_room(environment(me),set_color("开始用力的吸血 !!\n","HIR"),({}));
	me->set_temp("msg_stop_attack","(「吸血皇帝大」，其他事待会儿再说！)\n");
	
	me->set_temp("bloodsuck", 1);

	call_out("stop_suck", 4, this_object(), dest );
	return 1;
}

void stop_suck(object me, object victim)
{
	int blood;
	if( !me ) return;
	if( !victim ) {
		call_out("bloodsuck_again", 10+2*(int)me->query_level(), me);
		return;
	}
	tell_object( me, 
		"你愉快地舔了舔沾满鲜血的嘴唇，一股满足感使你恢复了一些体力！\n");

	tell_room( environment(me), 
		sprintf("%s愉快地舔了舔沾满鲜血的嘴唇，露出一个满足的表情。\n",
			me->query("c_name")), me );
	blood = random(me->query_level());
	me->receive_healing( blood );
	victim->receive_special_damage( "evil", blood+blood );
	call_out("bloodsuck_again", 20+2*(int)me->query_level(), me);
}

void bloodsuck_again(object me)
{
	if( !me ) return;
	me->set_temp("bloodsuck",0);
}
