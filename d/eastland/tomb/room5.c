#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下甬道");
	set_long( 
@C_LONG_DESCRIPTION
这儿是一个长长的甬道，你可以看到前方隐约传来的亮光。一阵阵的风从前方吹来，
你想大概快到了吧.......
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/room6", 
		"south" : TOMB"/room4",  ]) );
	reset();	
#include <replace_room.h>
}

