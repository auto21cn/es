// File: /d/eastland/ianyeu/hamlet_path1.c
// Generated by Roommaker Wed May 15 19:37:15 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("小径");
	ob->set_long( @LONG_DESCRIPTION
你正走在烟雨村内的小径上。当你往前走时, 你感觉到
这儿似乎是人烟稀少; 不仅屋宇疏落, 连小路上都杂草丛生,
你不禁怀疑这是否为一个废弃的村庄! 不过你注意到在东、
西两方各有一间小屋。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"southwest" : "/d/eastland/13,14.east", 
		"east" : "/d/eastland/ianyeu/wang_home", 
		"north" : "/d/eastland/ianyeu/hamlet_path2", 
		"west" : "/d/eastland/ianyeu/hunter_house" ]) );
	ob->reset();
}
