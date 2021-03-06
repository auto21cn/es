#include "../legend.h"

inherit LAKE"in_lake1";

void create()
{
        ::create();
    set_short("大海");
        set_long( 
@LONG
你划著船桨来到了海面上，极目四眺，是一片风平浪静的无垠大海，远处几艘
渔船正随著波浪载浮载沈，撒网成群，辛勤地捕著渔。波面上不时穿梭著飞鱼，阳
光反射其身上，好似一颗颗亮晶晶的银宝石。在旁边不远处似乎有一座岛屿，你不
禁往水底下一看，似乎划到了浅滩，或许你可以(get_off)下船看看。
LONG
    );
  ::reset();   
}

void init()
{
 ::init(); 
 add_action("do_get_off","get_off");
}

int do_get_off()
{ 
  if (present("oak oar",this_player()))
    get_object("oar",this_player())->remove(); 
  tell_object(this_player(),
       "你把船桨放下，脚踏处似乎是一处浅滩，你破水而行，来到了一块沙滩上。\n");
  this_player()->move_player("/d/eastland/story/area/coast1.c","SNEAK");
//  this_player()->move_player("/d/eastland/17,6.east","SNEAK");
  tell_room(environment(this_player()),sprintf(
       "%s从浅滩破水而来。\n",this_player()->query("c_name")),
       this_player());
  return 1;
}
