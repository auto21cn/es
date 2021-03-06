
#include "../echobomber.h"
#include <stats.h>

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name("huge bat", "巨蝙蝠");
	add("id",({"bat"}));
	set_short("A huge bat", "巨蝙蝠");
	set_long(
	    "A huge bat.",
	    "一只巨大的蝙蝠.\n"
	);
	set( "unit", "只" );
	set( "alignment", -200 );
	set("aggressive",1);
	set_natural_weapon(30,20,25);
	set_natural_armor(55,15);
	set( "tactic_func", "bite_you" );
	set_c_limbs( ({ "头部", "身体","翅膀" }) );
	set_c_verbs( ({ "%s张开它的大口，用它的牙齿向%s咬去" }) );
}

int bite_you()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "这巨大的蝙蝠用它的牙齿吸你的血.\n"
		  );
	  victim->receive_damage(30+random(10));	
	  report(this_object(),victim);
	  return 1;
      }
}
