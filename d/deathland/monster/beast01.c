#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "shadow beast", "幻影魔兽" );
	add("id",({"beast"}));
	set_short( "an shadow beast", "幻影魔兽" );
	set_long(
		"a terrible shadow beast.\n",
		"一个令人惧怕的幻影魔兽 ,没有人知道它的来历.\n"
	);
	set( "alignment", -1000 );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 25 );
	set_skill( "dodge", 100 );
	set_natural_armor(88,15);
 	set_natural_weapon(45,20,30);
    set( "special_defense", (  ["all":25, "none": 15]  ) );
    set ("aim_difficulty",([ "critical":35 ]) );
    set ("unbleeding",1);
    set ("killer",1);
    set ("wealth", ([ "gold": 250]) );
    set( "tactic_func", "my_tactic");
}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "幻影魔兽突然咬你.\n" );
      tell_room(environment(this_object()),
          "幻影魔兽突然咬"+victim->query("c_name")+".\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 40 + random(50) );
      report(this_object(),victim);
      return 1;
      }
}
