// File: /d/noden/drow/r06.c
// Generated by Roommaker Mon Nov 27 14:19:28 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地下广场");
	ob->set_long( @LONG_DESCRIPTION
这是一个地下大广场，你已经折服於黑暗精灵族的建筑手艺，竟然
能在这由岩石所构成的地底下，建构这种大广场，这里平时是黑暗精灵
族人的主要活动场所，也是他们集会，和外来人们交换生活物资的地方
，黑暗精灵没有钱币的交易，大多以物易物。
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"southwest" : "/d/noden/drow/r08", 
		"north" : "/d/noden/drow/r03", 
		"south" : "/d/noden/drow/r12", 
		"southeast" : "/d/noden/drow/r09" ]) );
	ob->reset();
}
