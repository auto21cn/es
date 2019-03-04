// lib9.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．阅览室");
    set_long(@C_LONG
这里是大图书馆的阅览室，石制的桌椅迄今仍完整地安置著，一如它们往日
所在的位置。这静谧的阅览室，不知已沈睡了多少日子了，但是室内的一切却仍
然非常洁净，可见魔族古帝国建筑技术的高超。
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib10",
 	"down" : AREA"lib0"
	]) );
    set("light", 1);
    reset();
}
    
