// tower5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔术师塔．第二层");
    set_long(@C_LONG
这里是魔术师塔的第二层，地板上画满了密密麻麻的奇特咒文，似乎是用
来禁制某种可怕的生物用的。空气中充满了腐尸的气味，你的直觉告诉你如果
不快点设法离开这个地方，恐怕不久之後你也会变成一具尸体了。
C_LONG
	    );
    set("exits", ([
	"east" : AREA"tower4",
	"north" : AREA"tower6"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write(@HINT
你看见地上写著：

	零啊零啊是这里，
	一啊一啊嘻嘻嘻，
	二啊二啊哩哩哩，
	三啊三啊滚出去，
	四啊四啊死回去，
	五六七啊跑跑跑，
	八九十还是嘻嘻嘻，
	迷宫乱乱真有趣，
	难难难难难死你。

这 .... 这是哪一国的儿歌啊? ....
HINT
	);
    return 1;
}

