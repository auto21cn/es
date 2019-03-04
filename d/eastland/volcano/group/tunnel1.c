#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("秘道");
	set_long( 
@LONG_DESCRIPTION
你正在一个黑黝黝的秘道中，你感觉到一丝冷意，你看到一只小老鼠在角落正在发
抖，以你的第六感可以感觉到再往前走去，可能会有危险。
LONG_DESCRIPTION
	);
set( "exits", ([
     "up" : OGROUP"warea9",
     "west" : OGROUP"tunnel2"
     ]) );
reset();
}
void init()
{
     if(this_player()) this_player()->set_explore("eastland#38");
}
