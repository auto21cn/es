#include "../layuter.h"

inherit ROOM;

void create()
{   
    object lord;

	::create();
	set_short("王屋");
	set_long( @LONG_DESCRIPTION
  这里是一个树洞房间，有一张巨大的石椅放在屋子的北边，上面刻满
  天马图样，而地面铺著漂亮的锦织地毯使整个房间看起来高贵异常，
  屋顶有一巨大的饰灯，由此发出的光线照亮整个房间。
LONG_DESCRIPTION
	);

	lord=new( "/d/noden/elf/monster/lord" );
	lord->move( this_object() );

	set( "light", 1 );
	set( "exits", ([
		"south" :LELF"elf32"
	]) );
	reset();	
}

int clean_up() { return 0; }
