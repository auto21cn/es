#include "../island.h"
#include <mudlib.h>
#include <stats.h>

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("octpus", "章鱼");
	add("id",({"octpus"}));
	set_short("章鱼");
	set_long(@LONG
一只大型的章鱼，正用著它的触手寻找食物，请不要惹它。
LONG
	);
	set( "unit", "只" );
	set( "alignment", -250 );
	set("max_hp",400);
	set("likefish",1);
	set("hit_points",400);
	set_natural_weapon(30,9,15);
	set_natural_armor(40,10);
	set( "unarmed" , 40 );
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "头部", "触手" }) );
	set_c_verbs( ({ "%s挥动它的触手向%s鞭打而去" }) );
}

int emit_lick()
{
	object victim;

	if( random(25)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "\n这章鱼用它的触手把"+victim->query("c_name")+"紧紧地捆住\n\n"
		  );
	  victim->receive_damage(1+random(3));
	  report( victim );	
	  return 1;
      }
}
