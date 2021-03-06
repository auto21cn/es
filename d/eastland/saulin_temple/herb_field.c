#include "saulin_temple.h"

inherit ROOM;

void create()
{
	object well;
	::create();
	set_short( "药圃");
	set_long( @C_LONG_DESCRIPTION
这里是一片宽阔的药圃，圃中一畦畦的田地种著许\多奇奇怪怪的植物，大多
是你从来也没见过的，不知道天心大师是从哪里收集来这麽多的药草？药圃的东
边还有一块空地，是用来种(plant) 新的药草的，东北角还有一个井(well)，是
药圃的灌溉水源。
C_LONG_DESCRIPTION
	);
    well = new(SAULIN_OBJ"dry_well");
    well->move(this_object());
    set_outside("eastland");
	set( "exits", ([ "west" : SAULIN"herb_room", ]) );
	reset();	
}

void init()
{
    add_action("climb_well", "climb");
}

int climb_well(string arg)
{
	if( !arg || arg!="well" )
      return notify_fail("爬什麽？\n");
    tell_object( this_player(), 
      "你小心的沿著井缘爬下井底，突然，脚下一个踩空....\n" 
    );
    tell_room( this_object(), 
      this_player()->query("c_cap_name")+
      "试著爬入井底...哎呀! 他头下脚上的栽进去了，技术实在是 ...\n"
      ,this_player()
    );
    this_player()->move_player( SAULIN"under_well1", "SNEAK" );
    tell_room( environment(this_player()), 
      this_player()->query("c_cap_name") + "从井口直直的栽了下来。\n"
      ,this_player()
    );
    return 1;
}
