// File: /d/noden/asterism/tower2-5.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的第五层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中矮人高塔的第五层,矮人的会议室,许许多多的重大决定
都是在此地产生的。这里有一个大的会议桌, 及数十张的椅子,墙上挂著一张矮人王
阿莱特斯一世的画像(painting).除此之外,从窗口望出去,你能看到雄伟的高山耸立
著,上面还有一曾白雾笼罩著。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
                "up"  :ASTR"tower2-6",
		"down":ASTR"tower2-4",
		]) );
	set("objects",([
	    "knight":MOB"dwarf_knight",
	    "mage"  :MOB"dwarf_mage",
	    ]) );
	reset();
}
