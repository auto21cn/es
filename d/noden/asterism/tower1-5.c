// File: /d/noden/asterism/tower1-5.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("半身人高塔的第五层");
	set_long( 
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中半身人高塔的第五层,空空荡荡的是这房间的特色.其实这
里是魔法师的冥想室.因此这里非常的寂静.在往上一层就是半身人族长的房间了.
C_LONG_DESCRIPTION
	);

    	set("objects",([
    	    "redmage":MOB"halfling_mage01",
    	    "blackmage":MOB"halfling_mage02",
    	    ]) );
    	set( "exits", ([ 
		"up" : ASTR"tower1-6",
		"down":ASTR"tower1-4",
		]) );

	create_door("up","down",([
             "name":"white door",
             "c_name":"白色的门",
             "keyword":({"white door","door",}),
             "c_desc":"白色的门",
             "status":"locked",
             "desc":"a white door",
             "lock":"ASTERISM_1",
                     ]) );
	reset();
}
