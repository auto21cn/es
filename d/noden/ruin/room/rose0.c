// rose0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("废墟");
    set_long(@C_LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。地上似乎有条
小径通往北方，你不禁觉得奇怪，这个鸟不生蛋的地方除了你这麽无聊的人之
外还有谁会来呢？
C_LONG
    );
    set("exits", (["north" : AREA"rose1"]) );

    reset();
}
