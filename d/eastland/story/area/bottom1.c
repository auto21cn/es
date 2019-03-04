#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("溪谷沙岸");
	set_long( @LONG
你立足之处是一溪谷里的沙岸，前面溪水从东南缓缓流向西北，渐渐地注入一
个黑色的大洞。这溪谷两岸都是千仞高的山峰，除非胁生两翼、步纵万尺，否则断
难攀越而过。
LONG
	);
        set("light",1);
	set( "exits", ([ 
         "southeast" : SAREA"bottom2",
        ]) );
	reset();
}
