#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather gloves", "皮手套" );
	add( "id", ({ "gloves" }) );
	set_short( "皮手套" );
	set_long(@CLONG
这双皮手套是用一种深褐色的皮革制成的，不但保暖，兼可以
保护手部。
CLONG
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "leather" );
	set( "armor_class", 1 );
	set( "weight", 30 );
	set( "value", ({ 110, "silver" }) );
}
