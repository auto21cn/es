#include "oldcat.h"

inherit ROOM;

void create()
{
::create();
set_short("绿林");
set_long( 
@LONG_DESCRIPTION
你站在一片绿色树林的小径中，这片欣欣向荣的树林，使你有陶醉在大自然的
感觉，在这茂密的树林之中，你还可以听到鸟鸣声，间些传来一阵不知虫名发出的
声音，这条小径不知道会通向何处。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest": "/d/eastland/5,1.east",
     "east" : ONEW"wild2", ]) );
set( "objects", ([
     "ohio":OMONSTER"ohio" 
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
