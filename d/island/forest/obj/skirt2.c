#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Pracrice pants","武道裤裙");
    add("id",({"skirt","pants"}) );
    set_short("武道裤裙");
    set_long(@LONG
这是一般的武道裤裙，乃一般习武之士习武时必著之装备！
LONG
            );
    set("unit","件");
    set("type","legs");
    set("material","cloth");
    set("armor_class",2);
    set("defense_bonus",0);
    set("weight",50);
    set("value",({20,"silver"}) );
}
    