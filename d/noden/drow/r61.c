
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("tuen2","宁静石道");
       set_long(@C_LONG
经过了冗长的步行後，你到了石道的尽头，这边感觉稍
为寒冷，令你不禁打了个寒颤，前面有个石阶，不知会通往
何处？你注意到在脚边，有不少的毛皮与枯树根散落一地，
看来似乎有生物的踪迹。
C_LONG);
       set("exits",([
                     "northup":"/d/noden/drow/r62",
                     "southup":"/d/noden/drow/r60"
                    ]));
       set("light",1);
       set("object",([
                      "rat":"/d/noden/drow/mob/m22 "
                   ]));

}
