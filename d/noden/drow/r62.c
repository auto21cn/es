#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("coldtune","寒冷的石阶");
       set_long(@C_LONG
这条幽长的石阶不知延伸到何处，但是由於四壁上仍插
有火把，看起来并不会令人感到害怕，但是由於越来越冷的
环境，令你忍不住打了个寒颤。
C_LONG );
       set("exits",([
                     "northup":"/d/noden/drow/r63",
                     "southdown":"/d/noden/drow/r61"
                    ]));
       set("light",1);
}
