// File: /d/noden/drow/r28.c
// Generated by Roommaker Mon Nov 27 14:18:27 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地下石阶");
	ob->set_long( @LONG_DESCRIPTION
这里是一处冗长的石阶，蜿蜒向下，你看不到石阶的尽头，墙上微弱
的火把还在闪烁著，但是好像快熄灭了，阶梯湿漉漉的，长有不少青苔，
你要小心步行，千万别滑倒了。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/noden/drow/r38", 
		"north" : "/d/noden/drow/r27" ]) );
	ob->reset();
}
