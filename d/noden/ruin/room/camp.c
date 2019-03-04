// camp.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("帐蓬内部");
    set_long(@C_LONG
这里是帐蓬的内部，帐蓬的顶上悬著一盏昏暗的油灯，墙角堆置著许多书
籍，看来这里的主人不但是个有学问的人，而且已经住在这里很久了。你注意
到了墙上挂著一幅奇怪的碑文 (rune) 拓片。
C_LONG
    );
    set("exits", (["out" : AREA"rose1"]) );
    set("light", 1);
    set("objects", (["explorer" : MOB"deltazeus"]) );

    reset();
}
 
