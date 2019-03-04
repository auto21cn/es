#include <almuhara.h>
 
inherit ROOM;
 
void create()
{
	::create();
	set_short("卧室");
	set_long( 
@C_LONG_DESCRIPTION
你走进了一间不大的卧室，和外面比较之下，这儿显的相当朴素。除了普通的家具外，
就数一个箱子最奇特。箱子成八卦形状，上面有著四个小凹槽，左右两旁各有一龙形的把手
，不知道是用来放什麽东西的。你环顾四周，却找不到什麽有趣的东西了。
C_LONG_DESCRIPTION
	);
 
	set( "exits", ([ 
		"north" : TOMB"/house2",  ]) );
	set( "objects", ([
		"wife" : MOB"/wife" ]) );
        set("c_item_desc",(["box":@C_LONG
这个箱子看来奇怪，但是你实在研究不出它是干啥用的......也许你该问问主人。
C_LONG
      ]));
	reset();	
#include <replace_room.h>
}
 
