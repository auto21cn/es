// Echo/item/letter03.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("Incantation paper of Lock","禁锢咒文");
add("id",({"paper","incantation paper",}) );
set_short("Incantation paper of Lock","禁锢咒文");
set("c_long",@LONG_D
一张写著奇怪符号咒文,只感到一种奇异的力量从纸上传来.
LONG_D
);

set( "unit", "张");
set("weight", 0);
set("prevent_drop",1);
}
