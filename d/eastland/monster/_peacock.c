#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(3);
	ob->set_name( "peacock", "孔雀" );
	ob->set_short( "孔雀" );
	ob->set_long(
		"这是一只非常漂亮的鸟\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 10 );

	ob->set( "unit", "只" );
	ob->set_natural_weapon( 2, 2, 4 );
	ob->set_c_verbs( ({ "%s用前爪抓向%s", "%s用它的嘴往%s啄去" }) );
	ob->set_c_limbs( ({ "头部", "尾巴", "腿部" }) );
}
