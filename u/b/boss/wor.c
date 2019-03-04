#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "工作室" );
	set_long(
		"这是一间新盖好的工作室，它目前空荡荡地没有任何东西。也许你第一件\n"
	"要做的就是在这里加一些东西。\n"
	);
        set( "light",1 );
        set( "exits", ([
      "guild" : "/d/wiz/wiz_hall",
        ]) );
}
