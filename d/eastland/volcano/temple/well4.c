#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "井底" );
	set_long(
@LONG
你正处在这口井的井底。前面一片明亮，好像有一栋建筑物，亮光正是从那里传来，
而且好像还有生物在那里的样子。
LONG
	);
	set( "exits", ([
             "south" : OTEMP"well3",
	     "north" : OTEMP"palace1",
	]) );
        reset();
}
