
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("竞技场");
        set_long( @LONG_DESCRIPTION
这里是鸟人族每年比武大会举行的地点，你可以看到四周空荡荡的啥都
没有，正是比武的好地方。不过，你却发现现在有点不一样，观察一下，你
似乎觉得四周隐隐约约传来野兽的咆啸及低声嘶吼的声音，看来，你得要自
求多福罗。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "south" : HAWK"square8",
                "north" : HAWK"square2",
                "west" : HAWK"square4",
                "east" : HAWK"square6",
                        ]) );
        set( "objects", ([
                "las" : MOB"las",
                "knight" : MOB"knight",
                        ]) );
        reset();
}//end of creat

