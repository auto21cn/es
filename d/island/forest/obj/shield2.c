#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Scale shield","鳞盾");
  add("id",({"scale","shield"}) );
  set_short("鳞盾");
  set_long(@LONG
这就是大蜥蜴所幻化而成的强力盾牌。
LONG
          );
  set("unit","面");
  set("type","shield");
  set("material","stone");
  set("armor_class",6);
  set("defense_bonus",1);
  set("weight",200);
  set("special_defense",(["fire":1,"sleet":1]) );
  set("value",({600,"silver"}) );
}
