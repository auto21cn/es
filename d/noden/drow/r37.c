#include "iigima.h"

inherit ROOM;

void create()
{

        ::create();
        set_short( "tunnel","废弃通道");
        set_long(

@C_LONG
通过禁地之门，这里一片荒芜，四周结满厚厚的蜘蛛网，地上到处是
灰尘，似乎很久没有人来过了，咦？地上好像有几片乾扁的蛇皮(skin)，
引起你的注意。
C_LONG
        );
        set( "exits", ([                     
                     "northwest": DROW"r36",
                     "southwest": DROW"r01",
        ]) );
       set("c_item_desc",(["skin":
@C_LONG
这些乾枯的蛇皮已经堆积了厚厚的一层了，看来这里曾繁殖了不少
的蛇，有的蛇皮还蛮软的，可能是有蛇刚蜕过皮吧。
C_LONG
]));
}
