#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地道");
	set_long(
@C_LONG_DESCRIPTION
这儿是一个阴暗的地道，四周是绝对的寂静，安静到除了脚步声外，就只有你自己的心
跳声。在这种环境中，你唯一想做的事就是赶快往前走，离开这个令人神经紧绷、心跳加速
的地方。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"up" : TOMB"/square9", 
		"down" : TOMB"/down2",  ]) );
	reset();
#include <replace_room.h>		
}

