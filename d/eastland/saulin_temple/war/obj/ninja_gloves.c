
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "ninja gloves", "忍者手套" );
        add( "id", ({ "gloves" }) );
        set_short( "忍者手套" );
        set_long(@C_LONG
这是一双忍者专用的黑色皮手套，不起眼的外表下，却有著超乎
平常的附著力，使得戴上它的人能在任何平滑的墙壁、屋顶来去
自如，不过看起来相当重。
C_LONG
        );
        set( "unit", "双" );
        set( "type", "hands" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "weight", 80 );	
	set( "value", ({ 950, "silver" }) );
}
