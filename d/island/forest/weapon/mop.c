#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Mop","拖把");
    set_short("拖把");
    set_long(@LONG
这是把拖把，它不会飞，只能用来拖地．
LONG
            );
     set("unit","把");
     set("type","longblade");
     set("weapon_class",5);
     set("min_damage",5);
     set("max_damage",8);
     set("weight",50);
     set("value",({10,"silver"}) );
}