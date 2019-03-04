#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "绿珠楼花厅" );
        set_long(
@LONG
这里是绿珠楼的花厅，厅堂四周都是一些美丽灿烂的奇花异草，
想必都是钱不多为了取悦他的如夫人而费尽心思搜罗来的，原来绿珠
是个喜爱莳花弄草的姑娘。
LONG
        );
        
        set( "exits", ([ 
		"down"   : Goomay"green_pearl",
        ]) );
        set( "objects", ([
                "lady" : Mob"green_lady",
		]));
        reset();
}

void init()
{
	if (this_player())
                this_player()->set_explore("eastland#10");
}
