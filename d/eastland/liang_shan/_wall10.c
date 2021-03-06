// File: /d/eastland/liang_shan/wall10.c
// Generated by Roommaker Tue Nov 21 15:59:46 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("栅上小路");
	ob->set_long( @LONG_DESCRIPTION
这里是梁山泊大寨上的小路，是为了防御攻击而建造的．但近几年
来，已没有人敢来侵犯了．站在这里，远方的风景一览无遗．木栅在这
里连接到山壁上，你注意到从寨内有条小路可通往此地．
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"eastdown" : "/d/eastland/liang_shan/path3", 
		"south" : "/d/eastland/liang_shan/wall9" ]) );
	ob->set( "objects", ([ 
		"shei1" : "/d/eastland/liang_shan/monster/shei1" ]) );
	ob->reset();
}
