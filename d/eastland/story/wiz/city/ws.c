#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("西大街");
	set_long( @LONG
你走正走在「巫咸城」内西大街上，大街往北边方向延伸，南边则是南大街。
近来城主有意发展西大街，遂把许多铺子迁移到这里来，一时人潮涌汹，贩夫走卒
不绝於途，声势颇有凌驾东大街之上！由此往北边可通往西门口，而你右手边是间
城内最大的药店。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"hospital1",
       	   "north" : SCITY"ww",
       	   "south" : SCITY"sw",
        ]) );
	reset();
}
