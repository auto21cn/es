#include "../oldcat.h"

inherit MONSTER;

#define life_damage 30
#define auto_heal 20
void create ()
{
	::create();
	set_level(17);
	set_name( "Right Guard", "右护法" );
	add ("id", ({ "guard" }) );
	set_short( "右护法－□□" );
	set_long( 
@LONG
右护法－□□原本是一只妖怪，具有可怕的魔力，原来居住在云南大泽中，
後来被龙王收伏後，成为龙王的护法，一起修炼而成正果。
LONG
	);
        set( "alignment", 8000 );
        set( "gender", "male" );
        set( "race", "undead" );
        set( "unit", "个" );
        set( "likefish",1);
	set_perm_stat( "dex", 27 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 15 );
	set_perm_stat( "piety", 10 );
	set_perm_stat( "karma", 20 );
	set ("max_hp", 900);
	set ("max_sp", 2500);
	set ("hit_points", 900);
	set ("spell_points", 2500);
	set ("wealth", ([ "gold": 100 ]) );
	set_natural_weapon( 2, 5, 10 );
	set_natural_armor( 65, 23 );
	set ("time_to_heal", 2);
	set ("unbleeding", 1);
	set ("aim_difficulty", ([ "critical":80, "weakest":100, "ganglion":100, ]) );
	set ("special_defense", ([ "all":90, "fire":45, "none":70 ]) );
    set ("weight", 400);
    set ("exp_reward",32590 );
    set_experience(950000);
    set ("tactic_func", "cast_spell");
    set_skill("wand",100);
    set_skill("dodge",70);
    set_skill("black-magic",100);
    set_skill("elemental",100);
    set_skill("target",100);
    set_skill("concentrate",100);
    set("magic_delay", 2);
    set("spells/sleet",3);
    set("spells/lightning",5);
    set("spells/ether-bolt",8);
    set("c_death_msg","%s的身体开始碎裂....终至消失。\n");
    set("chat_chance",5);
    set("att_chat_output", ({
      "\n□□说：你的小命已经在我的掌握之中，快投降吧。\n\n"
    }) );
    wield_weapon(OWEAPON"wand1");
    equip_armor(OARMOR"cloak2");
}

int cast_spell()
{// 40% call demon -> 60% little 40% great and continue attack.
 // if( hp < 100 ) -> 100% 再生 hp add 20-40 and continue attack.
 // if( hp < 300 ) -> 25% steal life force, damage 30-40 stop.
 // else 40% cast spell -> 70% sleet 3,  21% ether-bolt 8
 //      60% normal attack.
    object victim, monster;
    int damage;
    victim = query_attacker();
    if( !victim ) return 0;

    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2500);

    if( (this_object()->query("hit_points")<100) ) {
      tell_room( environment(victim), 
        "□□的身体再生又复原了。\n"
      );
      this_object()->receive_heal( auto_heal+random(auto_heal) );
    }
    if( (this_object()->query("hit_points")<300) && (random(20)<5) ) {
      tell_object( victim, 
        "□□眼睛射出一道青光，吸取你的生命力。\n"
      );
      tell_room( environment(victim),
        "你似忽看到"+victim->query("c_name")+
        "的灵魂飘至□□身上，□□的身体又复原了。\n",
        victim
      );
      damage = life_damage + random(10);
      victim->receive_special_damage("life", damage, 1);
      this_object()->receive_heal( damage );
      return 1;
    }
    
    if( random(10) < 4 ) return 0;
    
    if( random(10) < 7 )
      command("cast sleet on "+victim->query("name"));
    else
      command("cast ether-bolt on "+victim->query("name"));
    return 1;
}
