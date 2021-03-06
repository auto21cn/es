
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("frog", "青蛙");
	add("id",({"frog"}));
	set_short("A frog", "青蛙");
	set_long(
	    "A frog is searching the fly to eat.",
	    "一只正在寻找苍蝇来吃的青蛙.\n"
	);
	set("race","frog");
	set("c_race","青蛙");
	set( "unit", "只" );
	set( "alignment", -50 );
	set_natural_weapon(5,2,7);
	set_natural_armor(10,0);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "头部", "身体" }) );
	set_c_verbs( ({ "%s张开它的大口，用它的舌头向%s舔去" }) );
}

int emit_lick()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "这青蛙舔到了你的脸,让你觉得十分难受....\n"
		  );
	  victim->receive_damage(6+random(5));	
	  report(this_object(),victim);
	  return 1;
      }
}
