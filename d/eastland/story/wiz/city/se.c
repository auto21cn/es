#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("南大街");
	set_long( @LONG
你走正走在「巫咸城」内南大街上，大街往西边方向延伸，北边则是东大街。
东大街是城内最繁华的路段，人潮汹涌，络驿不绝，许多重要的铺子都在那里。由
於南大街是出入城内外必经之地，这里更是衔接著东大街，不时有巡逻捕役经过，
维持治安。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ss",
       	   "north" : SCITY"es"
        ]) );
        set("objects", ([
           "policeman#1":SWMOB"wiz_guard2",         
           "policeman#2":SWMOB"wiz_guard2",
        ]) );
	reset();
}
