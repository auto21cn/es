// File: /d/eastland/beggar/area/master_room.c
// Generated by Roommaker Thu Mar 21 18:11:42 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("『赏善罚恶厅』大厅");
	ob->set_long( @LONG_DESCRIPTION
这里是『赏善罚恶厅』,是丐帮用来奖励有功份子和处罚违反帮规或者为非作
歹的帮中份子。 一进来你就可以看到一幅『关公』像和一张大红桌子上摆著琳朗
目的家法,壁上挂著两口锋利的宝剑似乎警告著你不要做坏事, 否则後果不堪设想
!!大厅左侧有一个楼梯可以到二楼。 
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/beggar/area/master_roome.c", 
		"out" : "/d/eastland/beggar/area/north11.c", 
		"up" : "/d/eastland/beggar/area/master_roomu.c", 
		"west" : "/d/eastland/beggar/area/master_roomw.c" ]) );
	ob->set( "objects", ([ 
		"tan_male" : "/d/eastland/beggar/monster/tan_male.c", 
		"law_master" : "/d/eastland/beggar/monster/law_master.c", 
		"tan_female" : "/d/eastland/beggar/monster/tan_female.c" ]) );
	ob->reset();
}
