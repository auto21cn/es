#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long( 
@LONG_DESCRIPTION
一条长长的走廊，往东可以通到後院，往西可通向器物室，往南可以通到正殿。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OTEMP"temple23",
     "south" : OTEMP"temple11",
     "west" : OTEMP"temple22"
     ]) );
set("objects", ([
    "worker":OMONSTER"worker",
    ]) );
reset();
#include <../replace_room.h>
}
