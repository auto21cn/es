#include "../tsunami.h"
inherit WEAPON;

void create()
{
    set_name("Regular spear","制式长矛");
    add("id",({"spear"}) );
    set_short("制式长矛");
    set_long(@LONG
这是一把魔族军通用的长矛．
LONG
            );
    set("unit","把");
    set("type","thrusting");
    set("weapon_class",15);
    set("min_damage",10);
    set("max_damage",18);
    set("weight",150);
    set("value",({150,"silver"}) );                
}