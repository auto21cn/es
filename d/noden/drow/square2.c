
inherit ROOM;

void create()
{
        ::create();
        set_short("教练场");
        set_long( @LONG_DESCRIPTION
这里是黑暗精灵士兵平时训练的场地，你可以看到十馀个士兵正辛苦的
接受著操课。
LONG_DESCRIPTION
        );
        set( "objects", ([
		"tester" : "/d/noden/drow/mob/tester",
                        ]) );
        set( "exits", ([
                "north" : "/d/noden/drow/square1",
                     ]) );
    reset();
}//end of creat
