#include <takeda.h>

inherit ROOM;

void create()
{
	object dong;
	::create();
	set_short( "庭院月门" );
	set_long(
	"这是一个圆型的小门，在东方大陆，这种门通常是庭院的出入口，在门的\n"
	"另一边你看到一座小小的庭院(yard)，里面花木扶疏，但因距离太远，看不清\n"
	"楚种的是什麽。\n"
	);
        set( "c_item_desc", (["yard":
        "当你注视著这座庭院，有股说不出的诡异感觉在心中扩散，你的第六感阻\n"
        "止了你进入的念头。\n"
        ]));
        set_outside("eastland");
        set( "exits", ([
                "east" : TROOM"yard8",
                "south" : TROOM"hall"
        ]) );
        dong = new(TMONSTER"dong");
        dong->move(this_object());
        set( "pre_exit_func",([
               "east" : "check_leave"
        ]));
        reset();
}
int check_leave()
{
write( 
"走过这道大门，你的心情不由自主的紧张起来，就像走入了一片原始森林，自己\n"
"忽然没来由的觉得自己十分渺小，四面八方都像是充满了不可测的危险。\n\n");
return 0;
}
int clean_up() { return 0; }
