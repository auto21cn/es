// File: /d/eastland/beggar/area/wine_shop2.c
// Generated by Roommaker Thu Mar 21 18:11:07 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("『薪胆』客栈顶楼");
	ob->set_long( @LONG_DESCRIPTION
这里是『薪胆』客栈最高的一层楼,也是客栈最高价码的地方。这里通常用来
招待王公贵人或者是贵为一帮之主的地方,不是随便就可以来的。墙右角有一个楼
梯可以下到二楼。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"down" : "/d/eastland/beggar/area/wine_shop1.c" ]) );
	ob->set( "objects", ([ 
		"couple1" : "/d/eastland/beggar/monster/couple1.c", 
		"waiter" : "/d/eastland/beggar/monster/waiter.c", 
		"couple2" : "/d/eastland/beggar/monster/couple2.c" ]) );
	ob->reset();
}
