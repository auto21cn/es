// /u/e/echobomber/deathland/tent3.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("寂静的帐篷");
 set_long(@Long
一个非常安静的帐篷,与外界完全隔离著,当你一踏进这个地方时,就觉得
似乎有个魔法力场笼罩著整个地方.
Long
	);
       set("exits",(["out":Deathland"/main/d11",
                    ]));
       set("objects",(["retal":Monster"/retal",
                      ]));
       reset();
#include <../replace_room.h>
}

