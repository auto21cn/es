//#pragma save_binary

// fixed some word usage, grammer errors. - Elon 03-10-94
#include "moyada.h"

inherit ROOM;

void create()
{
	::create();
   set_short( "摩亚达西门" );
	set_long( @LONG_DESCRIPTION
你现在站在摩亚达城的西门，摩亚达城并没有城墙，但是整个城
除了北西两个城门以外，都被一道奇特的魔法结界围住，平常的人可
以自由进出结界，但是怀有敌意的人则无法通过结界。往东一条笔直
的石板路通往城中心的圆形广场与「银色之塔」。
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"east" : MOYADA"mainrd2.c", 
		"west" : "/d/noden/4,13.noden" ]) );
    set( "pre_exit_func", ([
      "east" : "to_enter",
    ]) );
    set( "no_monster", 1);
    set( "objects", ([
      "guard#1" : MOYADA"monster/moyada_guard",
      "guard#2" : MOYADA"monster/moyada_guard",
    ]) );
	reset();
}

int to_enter()
{
    if( !present("guard") || 
        (this_player()->query("alignment") > (-8000)) )
      return 0;
     tell_object( this_player(),
       "守卫说: 抱歉! 你不能通过。\n守卫阻止你进入莫亚达镇。\n" );
     tell_room( environment(this_player()),
       "守卫阻止"+this_player()->query("c_name")+"进入莫亚达镇。\n" ,
      this_player()
    );
    return 1;
}
