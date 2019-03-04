#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("hoe","锄头");
    add("id",({"spade"}) );
    set_short("锄头");
    set_long(@C_LONG
这是一把锄头！
C_LONG
             );
    set("unit","把");
    set("type","longblade");
    set("weapon_class",5);
    set("min_damage",5);
    set("max_damage",10);
    set("weight",100);
    set("value",({20,"silver"}) );
 }

