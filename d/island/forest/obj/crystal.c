#include "../tsunami.h"

inherit OBJECT;

void create()
{
     set_name("Red Crystal","红色的小水晶");
     add("id",({"crystal"}) );
     set_short("红色的小水晶");
     set_long(@LONG
这是魉皇鬼幻化而成的水晶，它不断地发出喵喵喵的叫声，加上不断的泛著红色
的闪光，使你觉得爱不释手！
LONG
              );
     set("unit","颗");
     set("weight",10);
     set("no_sale",1);
     set("give_to_sasami",1);
 }