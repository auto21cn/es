#include "../tsunami.h"

inherit ARMOR;

void create()
{
     set_name("Practice cloth","武道服");
     add("id",({"cloth"}) );
     set_short("武道服");
     set_long(@LONG
这是普通的武道服，一般练武术的人都会著这种服装来练武！
LONG
             );
     set("unit","件");
     set("type","body");
     set("material","cloth");
     set("armor_class",10);
     set("defense_bonus",0);
     set("weight",100);
     set("value",({50,"silver"}) );
 }
