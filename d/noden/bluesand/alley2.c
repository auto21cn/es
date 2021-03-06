#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
   set_short("小巷");
	set_long( @LONG_DESCRIPTION
这条小巷向南北方向延伸，西边的墙上似乎写著什麽东西(writing)，在
你的南边有一间小庙，东边是一栋东方式的建筑，雕梁画栋，看起来好像是有
钱人的住所，你可以敲门(knock)看看主人是否愿意让你参观一下。
LONG_DESCRIPTION
	);

	set_outside( "bluesand" );
	set( "item_desc", ([ 
		"writing" : "「徵临时工，待优，请敲门三下。」\n\n" ]) );
    set( "exits", ([ 
		"north" : "/d/noden/bluesand/alley1.c", 
		"south" : "/d/noden/bluesand/temple.c", 
		"east" : "/d/healer/building/healer_guild" ]) );
	create_door( "east", "west", ([
		"keyword" : ({ "arch door", "door" }),
		"name" : "arch door",
		"c_name" : "拱门",
            "c_desc" : "一扇红色的拱门，上面装饰著许多铜环。\n",
		"status" : "closed"
	]) );
	reset();
}

void init()
{
   add_action( "do_knock", "knock" );
}

int do_knock(string arg)
{
   if( !arg || arg != "door" )
   return notify_fail( "你要敲啥?\n" );
   if( (string)this_object()->query("doors/east/status")=="open" )
   return notify_fail( "门是开著的, 直接走进去吧。\n" );
   write( "你用力地擂门三下。\n" );
   tell_room( this_object(),
        this_player()->query("c_name")+"用力地擂门三下。\n",
        this_player() );
   message( "tell_room",
        "西边的门外传来「咚..咚..咚..」的敲门声。\n",
        "/d/healer/building/healer_guild", this_player() );
   return 1;
}
