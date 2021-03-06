#include <mudlib.h>
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "sheet", "纸人" );
	add( "id", ({ "sheet" }) );
	set_short( "纸人" );
	set_long(
		"你看到一个全身白衣、长发披肩，五官不清、面无表情的东西。\n"
	);
   set( "race", "undead" );
   set( "unbleeding", 1);
   set( "exp_reward",300) ;
   set( "aim_difficulty", ([
     "ganglion" : 100, "vascular" : 100 ]) );
	set( "gender", "female" );
	set( "alignment", -100 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "dex", 5 );
	set_skill( "dodge", 20 );
	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
	set( "alt_corpse", CAMPOBJ"paper" );
	set_c_verbs( ({"%s围成圈圈，压向%s"}) );
}

void die()
{
   tell_room( environment(this_object()), 
   query("c_name") + "化成一股白烟，消失了....你看到某个东西掉在地板上。\n",
      this_object() );
   ::die(1);
}
