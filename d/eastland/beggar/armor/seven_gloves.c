#include "../dony.h"

inherit ARMOR;

void create()
{
	set_name( "seven gloves", "七彩云套" );
	add( "id", ({ "seven","gloves" }) );
	set_short( "seven gloves", "七彩云套" );
	set_long(@C_LONG
这是一双由智慧草编织而成的手套，据说戴上它可以增加你的智慧哦 !!
C_LONG
	);
	set( "unit", "双" );
        set("material","cloth");
	set( "type", "hands" );
	set( "weight", 40 );
	set( "armor_class",3 );
        set( "defense_bonus", 5 );
	set( "value", ({ 240, "silver" }) );
}
