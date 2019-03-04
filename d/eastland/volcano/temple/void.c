#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "The Void", "一片虚无" );
	set_long("你放眼望去，四周尽是白茫茫的一片，看不到边境，难到这真的是神的世界吗 ? \n");
        set("exits",([
            "east":OTEMP"void",
            "west":OTEMP"void",
            "north":OTEMP"void",
            "south":OTEMP"void",
            ]) );
	set("light", 1);
}
