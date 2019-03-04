#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "yellow pallium","黄色袈裟" );
	add( "id", ({ "pallium","cloth" }) );
	set_short( "黄色袈裟" );
	set_long(
		"这是一套只有戒律院高级弟子才有资格穿著的黄色袈裟。\n"
	);
	set( "unit", "领" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
	set( "weight", 150 );
	set( "value", ({ 930, "silver" }) );
}
