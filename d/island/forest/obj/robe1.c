#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Dark Robe","黯云袍");
    add("id",({"robe"}) );
    set_short("黯云袍");
    set_long(@LONG
这是件法力袍，整件充满了黯淡的颜色，彷佛要把人吞噬一般。
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","wood");
    set("armor_class",23);
    set("defense_bonus",2);
    set("weight",150);
    set("value",({900,"silver"}) );
}
