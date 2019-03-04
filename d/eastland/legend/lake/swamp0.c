#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("沼泽");
        set_long( 
@LONG
你发现沿途上的如画美景似乎只到这里为止，往西看去，只见遍地枯木，沼气
氤氲。面前有一张告示贴在一具木架上，告示写道：

                危险！往西通往沼泽地带，沼泽内有『剧毒』瘴气，
           更有『极』凶猛吞人野兽，请爱惜性命，『千万绝对不要进入』。

LONG
    );
    set("exits",([
            "northeast":LAKE"village1",
            "west":LAKE"swamp1",
       ]) );
    set("objects",([
             "crab#1":LMONSTER"crab",
             "crab#2":LMONSTER"crab",
             "crab#3":LMONSTER"crab",
             "crab#4":LMONSTER"crab",
             "crab#5":LMONSTER"crab"
    ]) );
    reset();
}

