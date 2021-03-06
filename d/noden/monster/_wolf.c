#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "wild wolf", "野狼" );
	ob->add( "id", ({ "wolf" }) );
   ob->set_short( "野狼" );
	ob->set_long(
		"一头长满灰毛，满口利齿的野狼。\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 20 );
   ob->set( "race", "beast" );
	ob->set( "unit", "只" );
	ob->set( "natural_weapon_class1", 5 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 6 );
	ob->set( "killer", 1 );
	ob->set( "aggressive", 1 );

	ob->set_c_verbs( ({ "%s用前爪扑向%s", "%s张开满口利齿的嘴，往%s咬去" }) );
	ob->set_c_limbs( ({ "头部", "身体", "尾巴", "腿部" }) );
}
