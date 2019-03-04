// File: /d/noden/asterism/dungeon/path02.c

#include "../asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("halfling tower", "下水道的入口");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
    这儿是艾斯特律恩城引以为傲的下水道系统, 站在宽阔的入口, 在赞叹之馀
你不禁怀疑当初是怎样完成这项工程的。坚实的花岗岩石墙, 宽达数尺的水道, 
让你觉得这个设施的功能绝对不只是排水而已。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up" : DUNGEON"path01",
                "down":DUNGEON"sewer11",
		]) );
        set( "exit_msg",([
             "down":"就在$N跨入下水道的时候,一丝不祥的凉意流过你的心头。\n",
             ]) ) ;
	reset();
}


