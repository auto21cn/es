
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("??","矮人的育婴室");
    set_long(@Long
Long
,@CLong
一间矮人的育婴室,矮人族的大部分的生命由此产生.
CLong
    );
    set("exits",([
                "south":Deathland"/village/v45",
             ]));
    set("objects",([
        "nurse#1":Monster"/nurse",
        "nurse#2":Monster"/nurse",
        "baby#1" :Monster"/baby",
        "baby#2" :Monster"/baby",
        "baby#3" :Monster"/baby",
        "baby#4" :Monster"/baby",
          ]) );
    ::reset();
#include <../replace_room.h>
}
