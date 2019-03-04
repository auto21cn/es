// Echo/item/broom.c

#include "../echobomber.h"
inherit OBJECT;

void create()
{
     set_name("broom","扫把");
     set_short("a broom","扫把");
     set_long(
      "just a broom.\n",
      "一把普通的扫把.你可以拿著它去扫扫灰尘.\n"
      );
     set( "unit", "把");
     set("weight",35);
     set("value", ({ 10, "silver" }));
}
