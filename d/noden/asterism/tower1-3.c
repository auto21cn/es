// File: /d/noden/asterism/tower1-3.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("半身人高塔的第三层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中半身人高塔的第三层,一种快乐的气氛感染了你的心头,在
半身人无可救药的乐天派的影响下,他们认为一层的防卫措施已经足够,因此这里天天
都在开宴会,充满著欢笑的声音.
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"tower1-4",
		"down":ASTR"tower1-2",
		]) );
	set("objects",([
	     "explorer":MOB"halfling_explorer",
	     ]) );
	reset();
#include "replace_room.h"
}
