#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper ring", "黄铜指套");
   add( "id", ({ "ring" }) );
        set_short( "黄铜指套" );
        set_long(
@C_LONG
这是个黄铜制的手指套环，上面刻有蜘蛛的标志。
C_LONG
        );
        set( "unit", "只");
        set( "type", "finger" );
        set( "material", "heavy_metal" );
        set( "defense_bonus", 2 );
        set( "weight", 17 );
        set( "value", ({ 120, "silver" }) );
}
