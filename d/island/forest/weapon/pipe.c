#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Pipe","烟斗");
    set_short("烟斗");
    set_long(@LONG
这是用细竹做成的烟斗，前头还绑了个小小的烟草袋．
LONG
            );
    set("unit","把");
    set("type","dagger");
    set("weapon_class",4);
    set("min_damage",3);
    set("max_damage",6);
    set("weight",50);
    set("value",({20,"silver"}) );
}