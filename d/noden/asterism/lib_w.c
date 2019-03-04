// File: /d/noden/asterism/lib_w.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("Office of library administer", "图书馆馆长室");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
这个房间的布置蛮简朴的，偌大的房间中央摆了一张大大的办公桌。
四壁墙上挂了不下十幅的画，这是这个单调房间中唯一的点缀。
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["paintings":
             "一幅幅令人感到炫目的画，仔细一看全部都是用各色宝石镶成的.\n"
             "用宝石能“画”出肖像画，这种技术真是可怕。\n"]));       
	set( "exits", ([ 
		"east" :ASTR"lib01",
		]) );
//	set( "objects","Administer" : MOB"lib_adm" , ) ;
	
	reset();
	
}                         

