// File: /d/eastland/goomay/guess_house.c
// Generated by Roommaker Thu Nov 23 18:34:41 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("迎宾客栈");
	ob->set_long( @LONG_DESCRIPTION
这里是古梅镇的迎宾客栈，往来本镇的旅客和武林人士都常常在这里落脚歇马，
所以这里常常可以打听到各地的消息和传言，本店的小二哥更是非常热心「助人」
，如果你有什麽困难尽管向他开口，一定会得到帮助。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/mgate", 
		"north" : "/d/eastland/goomay/row14" ]) );
	ob->set( "objects", ([ 
		"house keeper" : "/d/eastland/goomay/monster/waiter" ]) );
	ob->reset();
}
