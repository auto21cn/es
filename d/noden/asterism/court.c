// File: /d/noden/asterism/court.c

#include "asterism.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("会议室前大厅");
	set_long(
		@C_LONG_DESCRIPTION
这里是三族长老评议会会议室前的广场，三族平时各事其政，除有紧急
事件发生外，三族长老只有在每年"圣战纪念日"时，才会结合"永恒之钥"
打开会议室大门。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
                    "south"  : ASTR"conferance_room",
		"north"  : ASTR"tower3-0",
		]) ) ;
		
	create_door("south","north",([
	            "name":"obsidian door",
                    "c_name":"黑曜石大门",
	            "keyword":({"obsidian door","door",}),
	            "c_desc":"一面黑曜石大门。"
	                     "你注意到在两扇门的中间接缝处有块三角形凹槽",
	            "status":"locked",
	            "lock":"ASTERISM_2",
	                         ])
	            ) ;
	                         
	reset();
}
