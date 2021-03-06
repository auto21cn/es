#include "../saulin_temple.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name("Mami mushroom", "灵芝妈妈");
	add("id",({"mami","mushroom"}));
	set_short("灵芝妈妈");
	set_long(
	    "一只正因为小孩被欺负而生气的灵芝妈妈，它正用愤怒的眼光瞪著你。\n"
	);
	set("unit", "只");
	set("alignment", 350 );
	set("killer",1);
	set("max_hp", 500);
	set("hit_points", 500);
	set_perm_stat("dex",20);
	set_perm_stat("str",16);
	set_perm_stat("int",18);
	set_natural_weapon(20, 12, 23);
	set_natural_armor(60, 24);
	set( "special_defense", ([ "all" : 40, "none" : 20 ]) );
	set( "aim_difficulty", ([ "ganglion" : 65, ]) );
	set( "unbleeding", 1);
	set( "tactic_func", "sleepy" );
	set( "alt_corpse", SAULIN_OBJ"big_pill" );
	set_c_verbs(({ "%s用头撞%s", "%s用身体撞%s" }));
	set_c_limbs(({ "身体", "头部" }));
	set("c_death_msg","%s突然毫无生气地躺在地上... 不动了。\n");
}

int sleepy()
{
	object victim;

	if( random(20)>6 || !(victim = query_attacker()) ) return 0;
    if( victim->query("stop_attack") ) return 0;
    tell_object( victim, 
      "灵芝妈妈散发出一种香气，你感到昏昏欲睡!!\n");

    tell_room( environment(this_object()), 
      "灵芝妈妈，散发出一种奇特的气息把"+victim->query("c_name")+"迷的不醒人事!!\n",
      ({ victim, this_object() })
    );
    victim->block_attack(6);
    victim->set_temp("msg_stop_attack", 
       "( 你现在全身无力，只想好好的睡一觉! )\n"
    );
    return 1;
}
