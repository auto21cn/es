// File: /d/noden/asterism/city14.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("A city road", "城市大路");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
这里是艾斯特律恩(asterism)城的大道路的尽头,由於半身人灵巧的
设计天份及矮人的建筑技巧 ,这里的道路十分宽敞笔直,而且道路的两旁
种植的树木花草在相互搭配之下,让人好像置身於一座优美的公园 .东边
是很坚固的城墙,在数百年的风吹日晒之下,依然屹立不摇.南边有一座高
塔(tower),上面插著矮人王阿莱特斯的旗子. 西南方有一条绿意盎然的小
径,似乎通往一处优静的地方。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
	    "tower":"一座建筑的很宏伟的高塔.\n"
	    ]) );
	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north":ASTR"city13",
		"southwest":ASTR"path1"
		]) );
	reset();
}

void init()
{
   add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str||str!="tower") return 0;
    write("你进入了塔中.\n");
    this_player()->move_player(ASTR"tower2-1",({
               "%s进入了塔中.\n","%s从外面进来.\n",}),"");
     return 1;
}
