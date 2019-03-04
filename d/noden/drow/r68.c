
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("back","神宫後殿");
       set_long(@C_LONG
经过长廊，你现在来到了神宫的後殿，这里有不少的桌
椅等等的，井然有绪地排列在两旁，你看到前面的一扇挂画
中画有赛亚达的塑像，但是可能是年代久远吧，已经蒙上了
些灰尘，後殿的天井由一些黑色的大理石雕刻而成，使得四
周看来有股阴凉的气息。
C_LONG );
       set("exits",([
                     "northwest":"/d/noden/drow/r69",
                     "south":"/d/noden/drow/r67"
                    ]));
       set("light",1);
}

