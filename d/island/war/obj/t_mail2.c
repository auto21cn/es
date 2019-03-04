#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Sikoku chianmail","黑面血甲");
    add("id",({"sikoku","chainmail","mail"}) );
    set_short("黑面血甲");
    set_long(@C_LONG
为了得到黑暗的加护，用黑血染成的铠甲，是战场的不祥物之一。
C_LONG
    );

    set("unit","件");
    set("type","body");
    set("material","light_metal");
    set("weight",100);
    set("armor_class",28);
    set("defense_bonus",6);
    set("value",({500,"silver"}) );
}
