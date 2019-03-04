#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下石室");
	set_long( 
@C_LONG_DESCRIPTION
你进入了一个不大的石室，四周的墙壁是用上好石砖砌成的。一些像是祭祀的用品整齐
地摆在这儿，只是看来已经很久没有人动过这些东西了。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west" : TOMB"/room1",  ]) );
	reset();	
#include <replace_room.h>
}

