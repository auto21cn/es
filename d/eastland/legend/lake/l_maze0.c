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
光反射其身上，好似一颗颗亮晶晶的银宝石。前面不远处就是海堤了，如果你累了
可以从这上堤岸休息(rest)。
LONG
    );
    ::reset();
}

void init()
{
  ::init();
  add_action("take_a_rest","rest");
}

int take_a_rest()
{
  object obj;
  if ( obj=present("oar",this_player())) obj->remove(); 
  this_player()->move_player(LAKE"village14","SNEAK");  
  tell_object(this_player(),
            "老船东笑著对你说 :这麽快就回来啦。然後一把把你拉上岸来。\n");
  tell_room(environment(this_player()),sprintf(
          "你看到%s下船走了过来。\n",this_player()->query("c_name")),
          this_player());
  return 1;
}