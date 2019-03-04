#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("玉石小径");
	set_long( @LONG
不知不觉你已经走到了玉石小径的尽头。小径通体红玉铺成，质若明晶，两旁
均是参天花树，因为树大枝繁，上面花枝纠结连成一片，一眼望去，直似两条花龙
锦城，蜿蜓飞舞。小径东边就是後花园了。

LONG
	);
        set("light",1);
        set("exits" , ([
           "northwest" : SPALACE"garden3",
                "east" : SPALACE"garden5",
        ]) );
        set("pre_exit_func",([
           "east":"can_pass"]));
        reset();
}
int can_pass()
{
    if ( this_player()->query("palace_war") ) return 1;
    return 0;
}