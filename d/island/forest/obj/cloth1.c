#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Police Uniform","警用紧身装");
    add("id",({"cloth","uniform"}) );
    set_short("警用紧身装");
    set_long(@LONG
这是魔族保安衙门中的勤务专用制服．当一位服勤中的保安官穿上它时，将会
忘了束缚的存在，同时也能给予使用者相当程度的防护，以提高侦办案件的效率．
LONG
            );
     set("unit","件");
     set("type","body");
     set("material","cloth");
     set("armor_class",30);
     set("defense_bonus",2);
     set("special_defense",(["divine":20,"mental":15,"fire":-15]) );
     set("weight",150);
     set("value",({600,"silver"}) );
}              