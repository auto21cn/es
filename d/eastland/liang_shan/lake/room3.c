#include <takeda.h>
#include <move.h>
#include <stats.h>
#include <conditions.h>

inherit ROOM;

int crumb_present = 1;

void create()
{
	::create();
	set_short( "民居" );
	set_long(
	"你进入了一间阴暗的房子，从这间屋子的杂乱陈设看来，屋主大概是个\n"
	"不修边幅的人，房子的中央放了一张大桌子(table)，上面放著一些锅子和碗\n"
	  );
        set("c_item_desc",(["table":
"这是一张普通的桌子，实用价值远远大於装饰价值，从放在桌子上的锅子\n"
"和碗筷看来，这张桌子应该是张餐\桌\，或许\你可以在这找到些吃的东西。\n"
            ]));        
        set( "exits", ([
                "east" : TROOM"village2"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 object crumb;
 if ( !arg || arg != "table")
    return notify_fail(
    "要找什麽?\n");
	if( !crumb_present )
		write(
		    "你翻烂了整张桌子，也没找到什麽好吃的....\n"
		);
	else {
		write(@ALONG
你在桌子上找来找去，什麽吃的都没找到，正当你想放弃时，你看到桌子的
缝隙中，有一些面包屑(crumb)，於是你顺手把面包屑挖出来。
ALONG
		);
		crumb_present = 0;
		crumb = new( "/d/eastland/liang_shan/obj/crumb" );
		if( (int)crumb->move(this_player()) != MOVE_OK )
			crumb->move( this_object() );
	        return 1;
	}
}
