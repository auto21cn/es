#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object item;
    
	::create();
	set_level(14);
	set_name( "strange jungle plant", "奇怪的丛林植物" );
	add("id",({"plant"}));
	set_short( "a strange green jungle plant", "奇怪的丛林植物" );
	set_long(
		"a strange green jungle plant.\n",
		"一种奇怪的绿色丛林植物,见到会动的就会主动攻击.\n"
	);
	set( "alignment", 0 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 16 );
	set_skill( "dodge", 95 );
	set_natural_armor(70,15);
 	set_natural_weapon(33,20,25);
    set( "special_defense", (  [ "all":25, "none": 25, "fire":-25 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
    set_c_verbs( ({ "%s伸出枝条快速击向%s"}) );
    set_c_limbs( ({ "枝条", "枝干" }) );
    set( "tactic_func", "my_tactic");
    
}

int my_tactic()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "这植物把你缠住并吸收你的精力.\n" );
      tell_room(environment(this_object()),
          "这植物把"+victim->query("c_name")+"缠住并吸收他的精力.\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 15 + random(20) );
      report(this_object(),victim);
      return 1;
      }
}
