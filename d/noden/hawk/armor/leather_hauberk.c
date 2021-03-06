#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather hauberk", "厚皮甲" );
	add( "id", ({ "hauberk" }) );
	set_short( "厚皮甲" );
	set_long(
		"这件厚重的皮甲是用野牛皮做成的，闻起来还带有一股皮革所特有的臭味。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 20 );
    set( "special_defense",
               ([ "cold":2, "electric":-3, "acid":2 ]) );
	set( "weight", 200 );
	set( "value", ({ 510, "silver" }) );
}
