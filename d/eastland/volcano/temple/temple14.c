#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long( 
@LONG_DESCRIPTION
一条长长的走廊，往南可以通到正殿，往东可通向起居室，往西可通向後院。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OTEMP"temple21",
     "south" : OTEMP"temple12",
     "west" : OTEMP"temple24"
     ]) );
set("objects", ([
    "worker":OMONSTER"worker",
    ]) );
reset();
#include <../replace_room.h>
}
