#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Alley", "穿堂");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这里是舞墨轩的二楼, 东南西北共有四间书房, 各曰「傲梅」、「碧兰」、
「墨竹」以及「冬菊」。
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
	set( "exits", ([ 
		"down"  : "/d/scholar/scholar/scholar_guild",
                "north" : "/d/scholar/scholar/gonfu_room2",
		"east" : "/d/scholar/scholar/ponder_room",
		"south"  : "/d/scholar/scholar/train_room",
                "up" : "/d/scholar/scholar/embattle_room",
		"west" : "/d/scholar/scholar/scholar_inner", ]) );
        set("objects",([
                "stone":"/d/scholar/scholar/stone1"]));
      	reset();
}
