#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓");
	set_long( 
@C_LONG_DESCRIPTION
这儿就是传说中的陵墓了，在你头顶上竟是一片璀璨的星空，众星们是用金钢钻做的，
而一轮明月则是一块皎洁无瑕的碧玉，冷冷的银光自星空洒下。在你东边躺著的是缩小版的
东方大陆 !! 地形山川、树木建筑无不维妙维肖，河流中甚至还有水在缓缓流动著，真是太
惊人了，不知道前人是如何创造出这般景象，委实令人敬佩。西边则是一面纯白色的墙壁，
找不出一点污迹。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north"  : TOMB"/inner6",
		"south"  : TOMB"/inner8"  ]) );
	reset();	
#include <replace_room.h>
}

