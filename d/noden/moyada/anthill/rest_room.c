// rest room sounds like .. WC :) -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
    set_short("休息室");
	set_long( @C_LONG_DESCRIPTION
这里是工蚁们休息的地方，四五只工蚁正在呼呼大睡。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"north" : MOYADA"anthill/cellar1",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant worker#3" : MOYADA"monster/ant_worker",
	   "ant worker#4" : MOYADA"monster/ant_worker",
	   "ant worker#5" : MOYADA"monster/ant_worker",
	   "ant worker#6" : MOYADA"monster/ant_worker",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",4);
}
