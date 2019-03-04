// File: /d/eastland/mumar/wall04.c
// Generated by Roommaker Sat Nov 25 13:51:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("牧马关城墙");
	ob->set_long( @LONG_DESCRIPTION
你走到了牧马关的北面的城墙上，整座牧马关也只有这儿朝北的一面才设有城垛
，满是伤痕的城垛似乎在诉说著战争的残酷。关外的黄色风景丝毫没有生气，有的只
是一片死寂。来往的骆驼商队缓慢地移动，是这片沙漠中唯一的点缀。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/mumar/wall05", 
		"south" : "/d/eastland/mumar/wall03" ]) );
	ob->reset();
}
