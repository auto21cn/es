#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "聚义厅" );
	set_long(
	"这里是梁山泊闻名天下的聚义厅，所有的头目们在这里歃血为盟，结\n"
	"成结拜兄弟，誓同生死，在东方大陆，这是友谊的最高表现。大厅的陈设\n"
	"非常简单，几张小蒲团，一个小香案，香案上一碗清水，几束香，一把牛\n"
	"耳尖刀，这就是全部的摆\设了。北边有一个小门可以离开这里。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "out"  : TROOM"path5",    
                "north"  : TROOM"path6",
        ]) );
        reset();
}
int clean_up() { return 0; }