#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」内北大街上，大街往东、西方向延伸。由於北大街地处
偏僻，往来无尘嚣，街旁树木稀稀落落於一排排的房子间，空气清幽，显的格外清
新脱落，街道内相当安静，是为居住之地。往东走可通往北门口，南边有一间小房
子，里面朗诵声音不断，原来是间私塾。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"nn",
            "west" : SCITY"wn2",
           "south" : SCITY"house2",
        ]) );
	reset();
}
