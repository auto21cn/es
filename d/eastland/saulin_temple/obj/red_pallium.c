#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red pallium","大红袈裟" );
	add( "id", ({ "pallium","cloth" }) );
	set_short( "大红袈裟" );
	set_long(
		"这是一套罗汉高级弟子才有资格穿著的大红袈裟。\n"
	);
	set( "unit", "领" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 5 );
	set( "weight", 150 );
	set( "value", ({ 930, "silver" }) );
}
