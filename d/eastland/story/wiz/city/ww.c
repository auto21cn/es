#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("西大街");
	set_long( @LONG
你走正走在「巫咸城」内西大街上，大街往北、南方向延伸，西边是西门口。
近来城主有意发展西大街，遂把许多铺子迁移到这里来，一时人潮涌汹，贩夫走卒
不绝於途，两旁皆是一排排的铺子。而你右手边是城内最大的旅馆，有提供休息服
务。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"hotel1",
       	    "west" : SCITY"westgate",
       	   "north" : SCITY"wn1",
       	   "south" : SCITY"ws",
        ]) );
	reset();
}
