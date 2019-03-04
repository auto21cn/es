
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace3","神宫侧殿");
       set_long(@C_LONG
一个由□木所雕刻的巨大书架占据了整个房间，这里就
是赛亚达神宫的右殿，据说赛亚达在世时，就以此地为其收
藏世界珍品与书籍的地方，後世黑暗精灵们怀念这位伟大的
骑士，便在他的故居，盖了大神宫，也将赛亚达生前的珍藏
放在此处，永久保存。
C_LONG );
       set("exits",([
                     "north":"/d/noden/drow/r68",
                     "west":"/d/noden/drow/r66"
                    ]));
       set("light",1);
}
