#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("村落");
    set_long(@LONG
『辰马镇』是津鸣城内魔族平民居住的一般村落。魔族动工建城前，便
已经确实做好都市规划，冀望一切建设都能使民族安定繁荣、国家快速发展
。因此所有的建设都以此构想为前提来进行。
LONG
             );
    set("light",1);
    set("exits",([
        "east":CITY"sway2"]) );
    set("objects",([
        "older":TMOB"older",
        "man":TMOB"man",
        "LADY":TMOB"lady"]) );
    reset();
#include <replace_room.h>
}



