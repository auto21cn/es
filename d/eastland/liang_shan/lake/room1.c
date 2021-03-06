#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "民居" );
	set_long(
	"你进入了一间低矮的房子，房子里没有什麽摆\设，给人一种空空荡荡\n"
	"的感觉。墙上有一个小窗子，正对著梁山泊大湖，湖上的凉风，不时从窗\n"
	"户中吹进来。窗下放著一张床，一个看来病的很重的老婆婆正躺在床上。\n"
	  );
        set("c_item_desc",(["bed":
"这是一张普通的木床，除了拿来睡觉以外，没有其它的功\能\。上面的被褥都很\n"
"乾净，由此看来这个老婆婆并不是无人照料。\n"
            ]));        
        set( "exits", ([
                "west" : TROOM"village2"
        ]));
        set( "objects", ([
                "lady" : TMONSTER"dapo"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 if ( !arg || arg != "bed")
    return notify_fail(
    "要找什麽?\n");
 if ( !present("da") ) 
    return notify_fail(
    "你在床上翻了半天，找不到任何可用的东西.....\n");
write(@ALONG
你在床上翻来翻去，不小心碰到老婆婆，把老婆婆吓醒了，老婆婆啐了你一口
骂道: 小兔崽子，没事在老娘床上作什麽? 你赶快起身站好
ALONG
		);
	        return 1;
}
