#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "大演武场" );
	set_long(
	"这里是山寨内著名的大演武场，平时豹子头林冲都在此操练部下．训\n"
	"练格斗或阵法．场边放著各式的兵刃，发出森森的寒光．如果你想加入山\n"
	"寨，最快的方法就是在此显显身手．北边的建筑即为点将台，林冲现在应\n"
	"该在里面．\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "exits", ([
                "east" : TROOM"plaza3",    
                "north"  : TROOM"plate",
                "west" : TROOM"plaza4",
                "south" : TROOM"flag"
        ]) );
        reset();
}
int clean_up() { return 0; }