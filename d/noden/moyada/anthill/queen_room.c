// something wrong with this room.. I dunno ;)  -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("王室");
	set_long( @C_LONG_DESCRIPTION
这里大概就是蚁后住的地方，并未显得富丽堂皇，只不过气氛显得有些
严肃。蚁后庞大的身躯几乎占满了整个房间，几只工蚁正在忙著把她产下的
卵运出去。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
      "north"  : MOYADA"anthill/square",
	]) );
	set( "no_monster", 1);
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant queen" : MOYADA"monster/ant_queen",
	   "kaisa ant#1" : MOYADA"monster/kaisa_ant",
	   "kaisa ant#2" : MOYADA"monster/kaisa_ant",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 5);
    ::reset();
}
