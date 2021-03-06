
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("山丘");
	set_long( @LONG_DESCRIPTION
    你正走在一由一些低矮山丘组成的丘陵地上，这里的地势起伏
并不很大，青郁的短草覆盖\著举目所及的山丘，几株大树散布在山
坡上，树间错落著几块巨□(rocks)。
LONG_DESCRIPTION
	);

	set_outside( "eastland" );
       set("c_item_desc",(["rocks":@C_LONG
    这些巨□不知道摆在这里几百年了，□上布满了青苔，你想走上前
去仔细打量它们，却发现近近的路怎麽走也走不到，走了半天，突然被
草丛里的某见东西绊了一交，原来是根粗绳(rope)，不知道谁把它钉在
草丛里。
C_LONG
			,"rope" : @ROPE
    你仔细看看这段绳索，发现它还不太旧，被人用木钉弯弯曲曲的钉
在地上，不知道有什麽用意，你想循著(follow)它去看看吗？
ROPE
]));

	set( "exits", ([ 
		"north" : "d/eastland/6,10.east", 
		"east" : "d/eastland/7,11.east" ]) );
	set( "original", "d/eastland/6,11" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 11 );
	reset();
}

void init()
{
	add_action("do_trace","follow");
}

int do_trace(string arg)
{
        if( !arg || arg!="rope" ) 
		return notify_fail("追踪什麽？\n");

        write("你顺著绳索弯弯曲曲的前进，突然，脚下一个踩空....\n");
        this_player()->set_explore("eastland#0");
        tell_room( this_object(), 
		  this_player()->query("c_cap_name") + "弯弯曲曲的走来走去，你听到一声大叫，然後人就不见了....\n",
                this_player() );
        this_player()->move_player( "/d/eastland/tomb/maze1", "SNEAK" );
        tell_room( "/d/eastland/tomb/maze1", 
                this_player()->query("c_cap_name") + "从上面的洞口掉了下来。\n",
                this_player() );
        return 1;
}
