#include <mudlib.h>

inherit ARMOR;

void create()
{
  set_name("Ratten shield","藤牌盾");
  add("id",({"ratten","shield"}) );
  set_short("藤牌盾");
  set_long(@LONG
这就是利用藤条编成的盾牌。
LONG
          );
  set("unit","面");
  set("type","shield");
  set("material","cloth");
  set("armor_class",4);
  set("defense_bonus",1);
  set("weight",100);
  set("value",({150,"silver"}) );
}
