#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "large shield", "大型盾" );
	add( "id", ({ "shield" }) );
	set_short( "大型盾" );
	set_long(
		"这个盾牌又大又厚，如果你熟悉用盾阻挡敌人的方法，这会是个不错的选择。\n"
	);
	set( "unit", "面" );
	set( "weight", 160 );
	set( "type", "shield" );
	set( "material" ,"heavy_metal" );
	set( "armor_class", 8 );
	set( "value", ({ 440, "silver" }) );
}
