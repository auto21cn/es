// File: /d/noden/asterism/dungeon/sewer11.c

#include "../asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("halfling tower", "下水道的入口");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
这儿是艾斯特律恩城最引以为傲的下水道系统。 石墙上昏暗摇曳的灯光 , 
为这个长长的甬道凭添了些许诡异的气氛。坚实的花岗岩墙, 宽达数尺的水道, 
再加上每隔十来步就有一片黑曜岩石板(slate)镶在甬道壁上,  让你觉得这个
设施的功能绝对不只是排水而已。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up"   : DUNGEON"path02",
                "east" : DUNGEON"sewer21",
                "south": DUNGEON"sewer12",                
		]) );
	reset();
}

void init()
{
     add_action("look_slate","look") ;
}

int look_slate(string arg)
{
    string msg ;
    string compared = ({ "slate" , "石板" , "黑曜岩石板"}) ;
    if( member_array(arg,compared,1) < 0 ) return 0 ;
    
    msg = CENTER->slate_desc(this_player(),this_object()) ;
    
    tell_object(this_player(),msg) ;
    
    return 1 ;
}


