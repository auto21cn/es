// File: /d/eastland/mumar/wall03.c
// Generated by Roommaker Sat Nov 25 13:51:26 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("牧马关城墙");
	ob->set_long( @LONG_DESCRIPTION
你正站在牧马关的城墙上，关内关外的风景在这儿可以一览无遗。关外是一片黄色
的沙漠世界，隐约还可以看到来往的骆驼商队，南边则是一片绿油油的稻田，和北边正
成了一个天地的对比。在不远的西南边，东方大国的重要军经中心－若岚城巍巍地耸立
在那儿，和这座牧马关成□角之势，互相保卫著。往东边，你看到有座城楼。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/mumar/stage01", 
		"south" : "/d/eastland/mumar/wall02", 
		"north" : "/d/eastland/mumar/wall04" ]) );
	ob->reset();
}
