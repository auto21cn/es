#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Holy Robe","圣光袍");
    add("id",({"robe"}) );
    set_short("圣光袍");
    set_long(@LONG
这是一件充满魔力的法袍，只见金光闪闪，彷佛是拥有取之不竭、用之不尽的强大能源
似的。
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","wood");
    set("armor_class",25);
    set("defense_bonus",2);
    set("weight",200);
    set("value",({700,"silver"}) );
}
