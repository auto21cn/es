// File: /d/noden/tamumu/cave5.c
// Generated by Roommaker Mon Dec  4 19:43:16 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("石室");
	ob->set_long( @LONG_DESCRIPTION
你来到一间不算太宽大的石室之中，一些石制的日用品和竹篓(basket)是这
里唯一的摆设，南边的一个架子上整齐地陈列著一堆....骷髅头(skulls)！看起
来你现在所在的地方并不是很安全，最好小心一点，以免成为它们的一份子。
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"north" : "/d/noden/tamumu/altar" ]) );
	ob->set( "item_desc", ([ 
		"skulls" : @LONG_TEXT
哇....二、三十个白森森的骷髅头排在一起，有些骷髅头上面还用刀子刻著
数字(numbers)，不知道是什麽意思？
LONG_TEXT
, 
		"basket" : @LONG_TEXT
这些竹篓大小不一，有的是圆的，有的是方的，有的背後还有用来背负的
背带或绳索，不知道里面装了些什麽东西？
LONG_TEXT
, 
		"numbers" : @LONG_TEXT
一、二、三......二十三、二十四，总共二十四个骷髅头，上面标示著从一
到二十四的数字。
LONG_TEXT
 ]) );
	ob->reset();
}
