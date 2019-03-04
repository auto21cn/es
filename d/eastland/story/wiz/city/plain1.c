#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("东郊");
	set_long( @LONG
这是「巫咸城」外的东郊，大约七、八十尺见方，除了西边可以进入「巫咸城
」，四周不远处皆是蓊蓊郁郁的树林。此间云淡风轻，空气清新，伴随著鸟啼蛙呜
，不时有鹿类隐藏林中奔相迳走，是个狩猎的好地方。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"eastgate",
            "north" : SCITY"plain2",
        ]) );
        set( "pre_exit_func", ([
            "north":"do_north",
            "west":"do_west"
        ]) );
	reset();
}
int do_north()
{
    if ( ( (this_player()->query_temp("north")) > 5 ) &&
         present("crystal glass",this_player()) ) { 
       this_player()->delete_temp("north");
       return 0;
    }       
    this_player()->move_player(SCITY"plain1","SNEAK");
    this_player()->add_temp("north",1);
    return 1;
} 
int do_west()
{
    this_player()->delete_temp("north");
    return 0;
}
