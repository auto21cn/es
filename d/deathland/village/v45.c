
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The entrance of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村庄的环庄道路上,这里有著非常和平安详的气氛,恍佛是一个世
外桃源.这里已经多年没有战争了,矮人们的童年几乎在此渡过.北边是矮人的育婴室,大
部份的矮人都是在此地出生的
CLong
    );
    set("exits",([
                "west":Deathland"/village/v35",
                "north":Deathland"/village/vr5",
                "east":Deathland"/village/v55",
             ]));
    ::reset();
#include <../replace_room.h>
}
