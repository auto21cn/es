#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓");
	set_long( 
@C_LONG_DESCRIPTION
你终於进到传说中的陵墓了 !! 你简直不敢相信你所看到的景象。在你头顶上竟是一片
璀璨的星空，众星们是用金钢钻做的，而一轮明月则是一块皎洁无瑕的碧玉，冷冷的银光自
星空洒下。在你面前躺著的竟是缩小版的东方大陆 !! 地形山川、树木建筑无不维妙维肖，
河流中甚至还有水在缓缓流动著，真是太惊人了，不知道前人是如何创造出这般景象，委实
令人敬佩。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/gate",
		"east"  : TOMB"/inner2",
		"west"  : TOMB"/inner8"  ]) );
	reset();	
#include <replace_room.h>
}

