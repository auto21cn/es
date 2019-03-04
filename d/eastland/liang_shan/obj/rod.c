#include "../takeda.h"
inherit OBJECT;

void create()
{
     set_name("fish rod","钓竿");
     set_short("fish rod","钓竿");
     set_long(
      "一根用竹子作成的简单钓竿，上面连著钓线，浮标和钓钩。\n"
      );
     set( "unit", "根");
     set("weight",40);
     set("value", ({ 20, "silver" }));
}
