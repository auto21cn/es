// eda0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市废墟");
    set_long(@C_LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。上方的洞口正
是你掉下来的地方，看来想从原路回去是不太可能的事。凛冽的冷风依然无情
地由四面八方吹来，令人感受到刺骨的寒意。
C_LONG
    );
    set("exits", ([ "north" : AREA"eda1" ]) );
    reset();
}


