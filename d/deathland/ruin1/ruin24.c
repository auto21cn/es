
// Deathland/ruin1/ruin24.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹");
     set_long(@Long
Long
,@CLong
一座破旧的遗迹 ,这里似乎已经荒废很久了 .地上到处是残砖破瓦 ,更让人觉得
这地方已经\许\久未曾有人烟了 .一种绿色的藓苔植物附在两旁的墙壁上 ,使得这地方
的气氛更显得十分的诡异 .
CLong
);
     set("exits",([
         "southeast":Deathland"/ruin1/ruin33",
         "northwest":Deathland"/ruin1/ruin15",
         ]) );
     ::reset();
#include <../replace_room.h>
}

