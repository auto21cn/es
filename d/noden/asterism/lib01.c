// File: /d/noden/asterism/lib01.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("图书馆大厅");
	set_long( 
		@C_LONG_DESCRIPTION
这里是艾斯特律恩(asterism)城的图书馆大厅。当初与魔族一战曾将这个
图书馆几乎摧毁殆尽。但在半身人的巧手之下，新的建筑让人感觉和文艺复兴
时期的巴洛克式建筑颇有神似处。墙上挂著一幅幅的画。空旷大厅中的参观者
寥寥可数，但是每个人都很尊重这里肃穆的气氛而尽量轻声细语。这儿仅有的
声响是你回汤在这空间中的脚步声。
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["paintings":
             "一幅幅令人感到炫目的画，仔细一看全部都是用各色宝石镶成的.\n"]));       
	set( "exits", ([ 
		"out"  :ASTR"city_library",
		"north":ASTR"lib_n",
		"south":ASTR"lib_s",
		"west" :ASTR"lib_w",
		]) );
	reset();
#include "replace_room.h"	
}                         

