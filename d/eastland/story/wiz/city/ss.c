#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("南大街");
	set_long( @LONG
你正走在「巫咸城」内南大街上，大街往东、西方向延伸，从这里往南走可到
达南门口。北边砌了几面新墙，那原本是通向城内最主要的大道，却因为某些缘故
，特地把它封了起来。在南大街上还有许多古色古香的建筑物，因为年代久远，不
少凋台危楼，城主命人大肆整建一番，平时用以吸引观光人潮。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"se",
       	    "west" : SCITY"sw",
       	   "south" : SCITY"southgate",
        ]) );
	set("objects", ([
	   "visitor":SWMOB"visitor2"
	]) );
	reset();
}
