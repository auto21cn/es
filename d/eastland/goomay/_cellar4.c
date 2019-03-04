// File: /d/eastland/goomay/cellar4.c
// Generated by Roommaker Thu Nov 23 18:49:37 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地洞");
	ob->set_long( @LONG_DESCRIPTION
你现在正位於一条阴暗的通道中，这条通道布满了许\多煤渣和炭灰，
通道两旁则规律地排放著一方方的火炉和铁□，这里原来可能是一个铁工厂
，从地面上四处乱丢的工具看来，原来的主人似乎走的很匆忙，而且再也不
曾回来过。这里没有任何的透气孔，可是不知道从哪里来的热风一阵阵地吹
来，你感觉燠热难耐....
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/eastland/goomay/cellar5", 
		"west" : "/d/eastland/goomay/cellar2" ]) );
	ob->set( "objects", ([ 
		"rat2" : "/d/eastland/goomay/monster/salamander", 
		"rat1" : "/d/eastland/goomay/monster/salamander" ]) );
	ob->reset();
}
