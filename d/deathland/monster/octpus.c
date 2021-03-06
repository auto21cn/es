
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name("octpus", "章鱼");
	add("id",({"octpus"}));
	set_short("An octpus", "章鱼");
	set_long(
	    "An octpus is searching the food to eat.",
	    "一只巨大的章鱼,正用著它的触手寻找食物\n"
	);
	set( "unit", "只" );
	set( "alignment", -550 );
	set("max_hp",400);
	set("likefish",1);
	set("hit_points",400);
	set_natural_weapon(23,12,19);
	set_natural_armor(30,0);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "头部", "触手" }) );
	set_c_verbs( ({ "%s挥动它的触手向%s鞭打而去" }) );
}

int emit_lick()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "这章鱼用他的触手把"+victim->query("c_name")+"紧紧地捆住\n"
		  );
	  victim->receive_damage(18+random(12));	
	  report(this_object(),victim);
	  return 1;
      }
}
