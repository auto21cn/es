#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("浮桥");
	set_long( @LONG
你站在浮桥上往四周观望，底下是一片白茫茫的断谷，不知道有多麽深；北方
的远处是层峦叠峰，一幕幕的绿布不住地往天际延伸；抬头一望，白云只不过离头
顶数尺高度；而东边是山顶，据说，巫咸国由此而去。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "hole"}) );
	set( "exits", ([ 
               "east" : SAREA"wiz1",
       	       "west" : SAREA"mountain4",
        ]) );
        set("exit",({"east","west"}));  
	reset();
}
