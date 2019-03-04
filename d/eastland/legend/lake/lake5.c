#include <mudlib.h>
#include "../legend.h"
inherit LAKE"in_lake";

void create()
{
    ::create();
    set_short( "lake2", "湖中" );
    set_long(@C_LONG
你走在湖中,脚底下是三□来许的『水板』而两旁都是千丈高的水墙。两旁水
声轰隆隆地快要把你的耳膜震破, 挟带著漫天的水气,不禁把你的全身都给濡湿了
。 水墙里一些七彩斑斓的鱼儿正悠闲地追逐玩耍,有时游近你身旁,一点也不怕你
的样子,你不禁伸手想要穿过水墙去触摸它们,却似乎有股力量阻挡著你。
C_LONG
    );
    set( "exit_suppress", ({
      "south","north" }) );
    set( "exits", ([
      "north":LAKE"lake6",
      "east":LAKE"lake3",
      "west":LAKE"lake2",
     "south":LAKE"lake1" 
    ]) );
    reset();
}
