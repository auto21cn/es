#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "swamp crab", "沼泽螃蟹" );
	ob->set_short( "沼泽螃蟹" );
	ob->set_long(
		"这是一种稀有的螃蟹，居住在沼泽和海洋的交界地带。\n"
	);
	ob->set( "natural_armor_class", 20 );
	ob->set( "unit", "只" );
	ob->set_c_verbs( ({ "%s用它的大螯往%s一夹" }) );
	ob->set_c_limbs( ({ "身体", "硬壳" }) );
}
