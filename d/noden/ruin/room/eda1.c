// eda1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市废墟");
    set_long(@C_LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。北方的不远处
似乎有亮光，似乎是有人居住的样子，说不定有出口呢！凛冽的冷风依然无情
地由四面八方吹来，令人感受到刺骨的寒意。
C_LONG
    );
    set("exits", ([ "north" : AREA"eda2" ]) );
    reset();
}

