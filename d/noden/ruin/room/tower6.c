// tower6.c

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
    switch(random(3))
    {
	case 0: set("exits", ([
		    "east" : AREA"tower7",
		    "south" : AREA"tower5"
		    ]));
		break;
	case 1: set("exits", ([
                    "west" : AREA"tower7",
                    "south" : AREA"tower5"
                    ]));
                break;
	case 2: set("exits", ([
                    "north" : AREA"tower7",
                    "south" : AREA"tower5"
                    ]));
                break;
    }
    reset();
}


