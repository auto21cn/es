#include <../takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "狭窄通道" );
	set_long(@C_LONG
你进入了山洞中的狭窄通道，潮湿而且阴暗，空气中弥漫著一股说不出来
的恶心气味，你仔细的分析它，有霉味，动物排□物的气味，甚至还有□体腐
败的味道，前面角落似乎有什麽东西蠢蠢欲动，无边无际的恐惧缓缓自你心中
升起，你的第六感命令你赶快离开...
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"forest1",
                "north" : TROOM"lair/lair2"
        ]) );
        reset();
}
int clean_up() { return 0; }
