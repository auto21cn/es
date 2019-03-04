#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Holy Hat","圣光帽");
    add("id",({"hat","cap"}) );
    set_short("圣光帽");
    set_long(@LONG
这是一件充满魔力的帽子，只见金光闪闪，彷佛是拥有取之不竭、用之不尽的强大能源
似的。
LONG
            );
    set("unit","件");
    set("type","head");
    set("material","wood");
    set("armor_class",6);
    set("defense_bonus",1);
    set("weight",100);
    set("value",({400,"silver"}) );
}
