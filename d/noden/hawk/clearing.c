// File: /d/noden/hawk/clearing.c
// Generated by Roommaker Sun Jan  9 02:36:37 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("半山腰");
	set_long( @C_LONG_DESCRIPTION
你现在来到半山腰的一处平地，西边的峭壁上有一处巨大的裂缝(crack)，南边
和东边都是断崖，这里有几间简陋的茅屋(hut)，看起来像是一般猎人外出时居住的
小屋，这里的土地大部分都是光秃秃的黏土，靠近断崖的地方长著几棵树(trees)，
从这里往下看，你好像可以看见山谷底下有一个圆形的祭坛之类地方。
C_LONG_DESCRIPTION
	);

	set_outside( "hawk" );
	set( "item_desc", ([ 
		"hut" : "这些茅屋大部分都空无一物，通常只有在狩猎季节才有猎人到这里暂住。\n", 
		"crack" : @LONG_TEXT
这个裂缝很大，看起来像是一个狭窄的山洞，恰可以容纳一个人进入(enter)，不
过你似乎隐约看见裂缝中有几对发亮的眼睛，或许是什麽野兽躲在里面。
LONG_TEXT
, 
		"trees" : @LONG_TEXT
这些树好像长期受到来自谷底的强风吹袭，枝干都朝同一个方向弯曲，看起来
诡异之至。
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"north" : "/d/noden/hawk/path4" ]) );
	set( "objects", ([
		"warrior": "/d/noden/hawk/monster/warrior" ]) );
	reset();
}

void init()
{
	add_action( "do_enter", "enter" );
}

int do_enter(string arg)
{
	switch( arg ) {
		case "hut":
			write( 
				"你逐一进入每一个小茅屋查看，但是并没有发现任何有趣的东西。\n"
                             );
       			return 1;
			break;
		case "crack":
			tell_room( environment(this_player()), 
				this_player()->query("c_name") + "将自己挤进山边的一个裂缝中。\n"
				,({this_player(),this_object() }) );
			this_player()->move_player( "/d/noden/hawk/crack1","SNEAK" );	
			return 1;
			break;
		default:
			return notify_fail( "进入哪里？\n" );
	}
}
