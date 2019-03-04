#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山顶");
	set_long( @LONG
在这山顶四周是层峦叠峰，好似一幕幕的绿布不住往天际延伸。天上白云离头
顶只不过尺许高度，一抹抹如条素色的被子，像要压将下来。东边底下是一白茫茫
的断崖，也不知道有多深。仰望东北方的天空，漂著一座四方形的建筑物。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "north" : SAREA"mountain2",
        ]) );
	reset();
}
