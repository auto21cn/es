#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Purple gloves","渲紫手套" );
        add( "id", ({ "gloves" }) );
        set_short( "渲紫手套" );
        set_long(
		"这是一双罕见的木制手套，上面渲染了美丽的紫色花纹。\n"
        );
        set( "unit", "双" );
	set("material","wood");
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "weight", 50 );
        set( "value", ({ 510, "silver" }) );
}
