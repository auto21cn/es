
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace1","神宫侧殿");
       set_long(@C_LONG
这里是赛亚达神宫的左殿，左殿的东边有一富丽的拱门
通往神宫主殿，这个大厅中央有一张白玉镶铜的石坛，上面
摆了不少的兵器，石坛角落并随时有一股白雾环绕在左右，
虽然年代已久，但兵器看来丝毫不受年代的影响，仍锋利如
新。
C_LONG );
       set("exits",([
                     "east":"/d/noden/drow/r66"
                    ]));
       set("light",1);
}
