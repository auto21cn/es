
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("iceroom","寒冷的洞穴");
       set_long(@C_LONG
经过了冗长的阶梯，你来到了一个寒冷的洞穴，四周都
结了一层薄薄的冰霜，更使你感到不快；你看到洞穴的北端
有扇大石门牢牢的锁著，而且似乎有几个人影在那晃动。
C_LONG );
       set("exits",([
                     "north":"/d/noden/drow/r64",
                     "southdown":"/d/noden/drow/r62"
                    ]));
       set("object",([
                      "guard":"/d/noden/drow/mob/m29",
                      "ghost":"/d/noden/drow/mob/m23"
                   ]));
}
