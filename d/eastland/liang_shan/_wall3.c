// File: /d/eastland/liang_shan/wall3.c
// Generated by Roommaker Tue Nov 21 16:01:36 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("栅上小路");
	ob->set_long( @LONG_DESCRIPTION
这里是梁山泊大寨上的小路，是为了防御攻击而建造的．但近几年
来，已没有人敢来侵犯了．站在这里，远方的风景一览无遗．小路在这
里转向北方，角落有一个木梯可通往上方的□望台．
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"up" : "/d/eastland/liang_shan/tower2", 
		"west" : "/d/eastland/liang_shan/wall2", 
		"north" : "/d/eastland/liang_shan/wall4" ]) );
	ob->reset();
}
