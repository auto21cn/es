// File: /d/deathland/palace/pa_09.c
// Generated by Roommaker Thu Nov 23 20:43:36 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("法拉第的起居室");
	ob->set_long( @LONG_DESCRIPTION
大儿子法拉第(Falady )的起居室.虽然法拉第已经死了,但是他的房间并
没有因此而被遗弃,这里仍然保持的一尘不染,就像法拉第生前一样.
墙壁上挂著一把很锐利的短剑,以及一个画有莫拉德皇室徽章的盾牌. 这两项
武器是法拉第生前最常用的武器.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/deathland/palace/pa_05" ]) );
	ob->reset();
}
