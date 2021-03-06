// File: /d/noden/asterism/conferance_room.c

#include "asterism.h"
inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("大会议室");
	set_long(
		@C_LONG
这里是三族最高评议会的大会议室，而这里也是评议会所定的禁地。
C_LONG
	);
  	set( "light", 1 );
	set( "exits",([
           	        "north" : ASTR"court",
                           "south" : ASTR"underpath",
		      ])  ) ;
	create_door("north","south",([
	            "name"   : "obsidian door",
               "c_name" : "黑曜石大门",
               "keyword": ({ "north door", "obsidian door", "door","gate", }),
	            "c_desc" : "黑曜石大门",
	            "status" : "locked",
	            "lock"   : "ASTERISM_2",
	                             ])
	            ) ;
   create_door("south","north",([
        "name"   : "obsidian door",
        "c_name" : "黑曜石大门",
        "keyword": ({ "south door", "obsidian door", "door","gate", }),
        "c_desc" : "黑曜石大门",
        "status" : "locked",
        "lock"   : "ASTERISM_2",
   ]) );
	reset();
}
