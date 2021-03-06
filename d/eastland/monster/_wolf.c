#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "hyaena", "土狼" );
	ob->set_short( "土狼" );
	ob->set_long(
		"你看到一只凶恶的土狼，对著你发出「呜呜」的低吼。\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 20 );

	ob->set( "unit", "只" );
	ob->set_natural_weapon( 5, 3, 6 );
	ob->set( "killer", 1 );
	ob->set( "aggressive", 1 );

	ob->set_c_verbs( ({ "%s用前爪扑向%s", "%s张开满口利齿的嘴，往%s咬去" }) );
	ob->set_c_limbs( ({ "头部", "身体", "尾巴", "腿部" }) );
}
