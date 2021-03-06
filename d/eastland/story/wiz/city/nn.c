#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」内北大街上，大街往东、西方向延伸。由於北大街地处
偏僻，往来无尘嚣，街旁树木稀稀落落於一排排的房子间，空气清幽，显的格外清
新脱落，街道内相当安静，是为居住之地。遥望南边不远处有座落一宫殿，那就是
城内最主要的建筑物－皇宫，耸立云端，富丽堂皇，是城民精神上的象徵。往北走
就北门口了。　
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"ne2",
       	    "west" : SCITY"nw2",
           "north" : SCITY"northgate",
        ]) );
	reset();
}
