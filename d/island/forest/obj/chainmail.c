#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Wind Chainmail","魔风之铠");
    add("id",({ "chainmail","mail"}) );
    set_short("魔风之铠");
    set_long(@LONG
这是魔族利用古魔法所创造出来的精致铠甲.
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","element");
    set("armor_class",25);
    set("defense_bonus",2);
    set("special_defense",(["fire":20,"cold":20]) );
    set("weight",250);
    set("value",({300,"gold"}) );
}
