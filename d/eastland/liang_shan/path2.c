#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "天王大道" );
	set_long(
	"这山寨内竟有一条街道，一条以整齐的青石板铺成的，不折不扣的街\n"
	"道．据说是为了纪念第一代老大: 托塔天王晁盖\而\命名．街道两旁，有各\n"
	"色各样的店铺，每一间店铺的生意都好的很，只不过店铺的门外，都没有\n"
	"招牌．北边有一个大广场．\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "no_monster",1);
        set( "exits", ([
                "east" : TROOM"store",
                "south"  : TROOM"path1",    
                "north"  : TROOM"flag",
                "west" : TROOM"wineshop"
        ]) );
}
int clean_up() { return 0; }