#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
        set_short( "寒鸦的小被窝" );
        set_long(
                "这是寒鸦和他的女人睡觉的地方,所以。。。没有事可别进来哦！\n"
	);
        set( "light",1 );

        set( "exits", ([

                "guild" : "/d/wiz/wiz_hall",
        ]) );
     reset();
}

