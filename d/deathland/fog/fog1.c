// /u/e/echobomber/deathland/fog1.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
        set_short("Fog","一片黑茫茫的雾");
set_long(@Long
Long
,@Clong
你已经进入了一片黑茫茫的雾里了. 四面八方都是一片黑色的雾海, 除了这里以外,
你完完全全地无法看见四周的环境, 若是你随意乱走的话, 说不定会掉入无底的深渊之
中. 当你每次迈开你的脚步离开这里去探险别的地方时, 你所须做的不仅是小心而已,
你还须要大量的运气.
Clong
	);
#include <../replace_room.h>
}
