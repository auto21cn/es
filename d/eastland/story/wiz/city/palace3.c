#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宫大殿");
	set_long( @LONG
印入眼帘里的是一脉连天接地闪闪发亮的万顷金黄色波涛，原来这里上天下地
左右墙壁都是用黄金铺成，显的贵气十足！两旁还有四根白玉雕成的巨大柱子，虽
然每一根刻划的都是龙的形态，但只只造形独特，表情不一，或潜或藏，或者盘旋
而起，进而张牙舞爪，个个令你叹为观止目不暇已，巧夺天工疑为鬼神莫测之造！
另外两旁各站著文官武将，讨论著事谊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "north" : SCITY"palace4",
           "south" : SCITY"palace2"
        ]) );
        set( "objects", ([
           "scholar" : SWMOB"wiz_scholar1",
           "general" : SWMOB"wiz_general1"
        ]) );
	reset();
}
