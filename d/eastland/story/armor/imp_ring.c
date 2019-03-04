#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("rainbow ring","七彩琉璃戒");
        add( "id", ({ "ring" }) );
        set_short( "七彩琉璃戒");
        set_long(@C_LONG
一只晶莹剔透不时在阳光的照射下闪烁著七彩光芒的戒指。七彩琉璃戒是「羽民族
大首领  羽后」年轻时四处争战所配带的戒指，防护力超强，是只连天神都为之赞
叹的稀世防具。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 6 );
        set( "weight", 10 );
        set( "value", ({ 7500, "silver" }) );
}



