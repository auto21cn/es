#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black suit","黑色劲装" );
	add( "id", ({ "suit","cloth" }) );
	set_short( "黑色劲装" );
	set_long(
		"这是钱形次郎早年犯案时惯用的服装，据说穿来特别身轻如燕。\n"
	);
	set( "unit", "领" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 40 );
        set( "defense_bonus", 5 );
	set( "weight", 100 );
	set( "value", ({ 1500, "silver" }) );
	set( "extra_stats" ,(["pie" : -1 , "dex" : 1 ]) );
}
