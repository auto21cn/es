#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Cloth feet","布鞋");
    add("id",({"boots","boot","feet"}) );
    set_short("布鞋");
    set_long(@LONG
这是树雷王家传统的布鞋，它的长相和一般的袜子有些类似，但是可以直接当
做鞋子穿！
LONG
            );
    set("unit","双");
    set("type","feet");
    set("material","cloth");
    set("armor_class",3);
    set("defense_bonus",0);
    set("weight",50);
    set("value",({10,"silver"}) );
}