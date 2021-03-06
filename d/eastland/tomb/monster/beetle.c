#include <races.h>

inherit RACE_INSECT;

void create()
{
	::create();
	set_level(2);
	set_name( "bamboo beetle", "笋龟" );
	add("id", ({"beetle"}) );
	set_short( "笋龟" );
	set_long(
		"一只小笋龟。\n"
	);
	set_perm_stat( "str", 5 );

	set( "unit", "只" );
	set( "alignment", 150 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4);
	set( "natural_max_damage1", 8);
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"小笋龟飞呀飞的，令你想起小时候。\n" }) );
	set_c_verbs( ({ "%s用角往%s一顶", "%s张开大牙，往%s咬去" }) );
	set_c_limbs( ({ "头部", "身体", "脚部", "甲壳" }) );
}
