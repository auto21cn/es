#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Turtle Boots","神龟战靴");
  add("id",({"turtle","boots"}) );
  set_short("神龟战靴");
  set_long(@LONG
这就是传说中用神龟的龟甲所作成的战靴。
LONG
          );
  set("unit","双");
  set("type","feet");
  set("material","stone");
  set("armor_class",8);
  set("defense_bonus",2);
  set("weight",100);
  set("value",({200,"gold"}) );
}
