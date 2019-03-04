
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("tune2","宁静石道");
       set_long(@C_LONG
这条倾斜的石道斜斜的向前延申，不知道尽头在何处，
石墙上，每隔几步便插了一根火把，你不会因此而迷失了方
向，甬道内静得出奇，没有丝毫声响，路的尽头彷佛找不著
似的，你仍要小心地前进。
C_LONG );
       set("exits",([
                     "northdown":"/d/noden/drow/r61",
                     "southup":"/d/noden/drow/r70",
                    ]));
       set("light",1);
       set("object",([
                      "ghost":"/d/noden/drow/mob/m21",
                   ]));

}
