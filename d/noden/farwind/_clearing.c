// File: /open/polo/noden/farwind/clearing.c
// Generated by Roommaker Mon Nov  6 06:28:50 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("河边空地");
	ob->set_long( @LONG_DESCRIPTION
这里是远风镇西南边的一块空地，你的南边和北边都是河水，西边被一道
围墙挡住，也许是东北边那户人家的院子，河边有许多卵石(pebble)和杂草，
你看到西边的围墙边好像有一堆鱼网(net)。
LONG_DESCRIPTION
	);

	ob->set_outside( "farwind" );
	ob->set( "exits", ([ 
		"north" : "/d/noden/farwind/path1" ]) );
	ob->set( "item_desc", ([ 
		"net" : "一堆纠结在一起的鱼网，看来大概不能用了。\n", 
		"pebble" : "这些石头大部分是圆的，显然是河流从上游冲下来的。\n" ]) );
	ob->set( "objects", ([ 
		"toad" : "/d/noden/farwind/monster/toad" ]) );
	ob->reset();
}
