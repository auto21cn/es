#include <mudlib.h>

void create(object ob)
{
	if (!ob ) return ;
	ob->set_level(1);
	ob->set_name( "beetle", "甲虫" );
   ob->set_short( "甲虫" );
	ob->set_long(
		"一只长著硬壳的长角甲虫，让你想起小时候 ....。\n"
	);
	ob->set_perm_stat( "str", 3 );
   ob->set( "race", "insect" );
	ob->set( "unit", "只" );
	ob->set( "alignment", -150 );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 2 );
	ob->set( "natural_max_damage1", 4 );
	ob->set_c_verbs( ({ "%s用角往%s一顶", "%s张开大牙，往%s咬去" }) );
	ob->set_c_limbs( ({ "头部", "身体", "脚部", "甲壳" }) );
}
