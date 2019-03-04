#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "kabuto", "头盔" );
   set_short( "日式头盔" );
	set_long(
		"这是一顶日式的头盔，上面有一对黄铜做成的鹿角饰。\n"
	);
	set( "unit", "顶" );
	set( "weight", 80 );
	set( "type", "head" );
	set( "material", "light_metal");
	set( "armor_class", 5 );
	set( "defense_bonus", 3 );
	set( "special_defense",
	       ([ "mental":3, "electric":-3, "acid":1 ]) );
	          
	set( "value", ({ 575, "silver" }) );
	set( "no_sale", 1 );
}
