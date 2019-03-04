// File: /d/eastland/easta/west_ent.c
// Generated by Roommaker Sat Nov 25 17:04:35 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("西大街路口");
	ob->set_long( @LONG_DESCRIPTION
你现在来到若岚城西门内的大街，若岚城以若岚宫为中心，东西东北环绕著
四条大街，西大街上所住的居民大多属於中下阶层的农人或工人，一片平房中夹
著几间独门独院的地主大宅，不过这些地主慑於布衣出身的萧相国之威，倒也不
敢对穷人过於苛刻，往东是西大街的主要街道，西边则是往城外的西门。
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/easta/west_malley", 
		"south" : "/d/eastland/easta/west_slane", 
		"north" : "/d/eastland/easta/west_nlane", 
		"west" : "/d/eastland/easta/westgate" ]) );
	ob->reset();
}
