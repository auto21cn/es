#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Radish","萝卜");
    set_short("萝卜");
    set_long(@LONG
这只是一般的红色圆形小萝卜!
LONG
            );
    set("unit","只");
    set("weight",50);
    set("value",({0,"silver"}) );
    set("give_me_radish",1);
 }

