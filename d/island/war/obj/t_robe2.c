#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Combat Robe","战斗法袍");
    add("id",({"robe"}) );
    set_short("战斗法袍");
    set_long(@LONG
这是件轻巧精致的法袍。
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","wood");
    set("armor_class",21);
    set("defense_bonus",4);
    set("weight",80);
    set("value",({700,"silver"}) );
}
