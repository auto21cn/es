// /u/m/mad/special/wolf.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name( "huge hyaena", "巨土狼" );
   add( "id", ({ "wolf" }) );
   set_short("巨土狼");
	set_long(
           "你看到一只凶恶的土狼，对著你发出「呜呜」的低吼。\n"
	);
   set( "race", "beast" );
   set( "unit", "只" );
   set_perm_stat( "str", 10 );
   set_skill( "dodge", 50 );
   set_natural_weapon( 20, 8, 20 );
   set_c_verbs( ({ "%s用前爪扑向%s", "%s张开满口利齿的嘴，往%s咬去" }) );
   set_c_limbs( ({ "头部", "身体", "尾巴", "腿部" }) );
}

void die()
{
   object killer;

   killer=query("last_attacker");
   killer->set_temp("killed_wolf",1);
   ::die();
}
