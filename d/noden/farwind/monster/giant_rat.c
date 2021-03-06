#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "giant rat", "巨老鼠" );
	add( "id", ({ "rat" }) );
	set_short( "巨老鼠" );
	set_long(
		"一只巨大的老鼠，你怀疑世界上有没有哪一只猫能打赢这只老鼠。\n"
	);
	set_perm_stat("dex", 5 );
	set_perm_stat("str", 7 );

	set_c_verbs( ({ "%s用爪子乱抓%s", "%s张嘴往%s咬下" }) );
	set_c_limbs( ({ "头部", "身体", "前爪", "後腿", "尾巴" }) );

	set( "unit", "只" );
	set( "natural_armor_class", 18 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set( "max_hp", 100 );
	set( "hit_points", 100 );
}
