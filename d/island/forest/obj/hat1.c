#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Dark Cap","黯云冠");
    add("id",({"hat","cap"}) );
    set_short("黯云冠");
    set_long(@LONG
这是件黯淡无光的帽子，可怕的颜色彷佛是要将人吞噬一般。
LONG
            );
    set("unit","件");
    set("type","head");
    set("material","wood");
    set("armor_class",6);
    set("defense_bonus",1);
    set("weight",100);
    set("value",({550,"silver"}) );
}
