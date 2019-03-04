#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("King ring","王者之戒");
        add( "id", ({ "ring" }) );
        set_short( "王者之戒");
        set_long(@C_LONG
一只晶莹剔透的戒指，在阳光的照射下闪烁著七彩光芒。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 3500, "silver" }) );
}



