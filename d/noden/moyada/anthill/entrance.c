// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("蚁穴入口");
	set_long( @C_LONG_DESCRIPTION
你处在这巨大蚁类的巢穴内，地上一个巨大的洞穴，你看到无数的工蚁正在
爬进爬出的搬运食物，这洞穴不知有多深，你也许可以爬(climb down)下去看看。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"out" : MOYADA"sand_square"
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant fighter"  : MOYADA"monster/ant_fighter",
	   "ant knight"   : MOYADA"monster/ant_knight",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",6);
}

void init()
{
    add_action("to_climb", "climb");
}

int to_climb( string str )
{
    if( !str || str=="" )
      return notify_fail("你要爬哪个方向?\n");
    if( str != "down" )
      return notify_fail("那个方向不通啦!\n");
    to_climb_down( this_player(), MOYADA"anthill/cellar1", 
      MOYADA"anthill/dump", 35, 20 );
    return 1;
}
