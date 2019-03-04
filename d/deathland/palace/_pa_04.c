// File: /d/deathland/palace/pa_04.c
// Generated by Roommaker Thu Nov 23 20:35:59 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("会议室");
	ob->set_long( @LONG_DESCRIPTION
这里是一间会议室,矮人常常在此地召开作战会议或是处理紧急事件.有一张
非常大的圆形会议桌在房间的中央,另外有数十张的椅子放在会议桌的旁边.而在
墙壁上挂著一张矮人国度的地图(map),以及莫拉德一世(Molader I)的画像.
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "c_item_desc", ([ 
		"map" : @LONG_TEXT
---------------------------------------------------------------------

                         教堂                  村落
                           |                     |
                           |                     |
--------------------------------------------------------皇宫
                           |                |
                           |                |
                         酒吧             矿坑


---------------------------------------------------------------------
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"south" : "/d/deathland/palace/pa_01" ]) );
	ob->set( "objects", ([ 
		"calford" : "/d/deathland/monster/calford" ]) );
	ob->reset();
}
