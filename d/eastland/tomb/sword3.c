#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("地下通道");
	set_long( 
@C_LONG_DESCRIPTION
这儿是一个阴暗的通道，四周极其地安静，你几乎可以听到自己的心跳和脚步声相呼应
著。由前方传来的寒意令你冷的直打哆嗦，这是以往从未曾有过的感觉，你不禁犹豫起来，
到底该不该继续往前走呢??
C_LONG_DESCRIPTION
	);
	
	set( "exits", ([ 
		"east"  : TOMB"/sword2",
		"west"  : TOMB"/sword4"  ]) );
	create_door( "west","east",
		   (["keyword" : ({"door", "iron"}),
		     "name"    : "iron door",
		     "c_name"  : "大铁门",
		     "desc"    : "A huge iron door\n",
		     "c_desc"  : "一扇坚固的大铁门。\n",		
		     "lock"    : "TOMBKEY_2",
		     "status"  : "locked",
		     ]) );		
	reset();	
}

