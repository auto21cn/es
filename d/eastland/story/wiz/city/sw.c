#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("南大街");
	set_long( @LONG
你走正走在「巫咸城」内南大街上，大街往东边方向延伸，北边则是西大街，
往东可通往南门口。在这条南大街上还有许多古色古香的建筑物，因为年代久远，
不少凋台危楼，更兼有不少死角，而北衔西大街，龙蛇混杂，治安令人深忧。  
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"ss",
       	   "north" : SCITY"ws",
        ]) );
	reset();
}
