#include <mudlib.h> 

inherit ROOM;

void create()
{
	::create();
	set_short("Color Wolf Association", "色狼俱乐部" );
	set_long(
"You are in Club of Color Wolf Association\n",
"这□是色狼俱乐部\n"
	);
	set( "light",1 );
	set( "exits", ([
		"out" : "/u/s/supertramp/workroom"
	]) );
	"/u/s/supertramp/cwa/cwa_board"->frog();
}

