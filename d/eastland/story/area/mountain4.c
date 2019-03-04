#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山顶");
	set_long( @LONG
在这山顶四周是层峦叠峰，好似一幕幕的绿布不住往天际延伸。天上白云离头
顶只不过尺许高度，一抹抹如条素色的被子，像要压将下来。往南俯视，与对山之
间衔接著一个溪谷和一座吊桥，那溪流，急湍澎湃，「刷刷」有声，不知高度若何
，否则大可一游而尽兴。在你东边是个断崖，里面白茫茫的一片，也不知道有多深
，另外在断崖上还漂著一座浮桥。
LONG
	);
        set("light",1);
	set( "exits", ([ 
              "east" : SAREA"bridge2",
       	      "west" : SAREA"bridge1",
        ]) );
        set("objects", ([
              "god":SMOB"lucky_god"
        ]) );
        set("exit",({"east","west"}));
	reset();
}
