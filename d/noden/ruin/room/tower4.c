// tower4.c

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
    set("objects", (["jitter" : MOB"jitter"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    if (this_player()->query_temp("lilia_direction") == 1)
    {
	write("你定睛一看，西边果然有个小门，暗暗地看不太清楚 ....\n");
	set("exits", (["west" : AREA"tower5"]));
        return 1;
    }
    else
        return 0;
}

