#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("中央大道");
    set_long(@LONG
这是津鸣城内最大的，也是唯一的主要道路，两旁种满了大树，随著时
光的流逝，树枝已经向两旁广泛的分展开来，如今，已经形成一个完美的天
然隧道了。
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "west":CITY"r6"]) );
    set("objects",([
          "woman" : TMOB"resident4"
                  ]) );
    reset();
#include <replace_room.h>
}
