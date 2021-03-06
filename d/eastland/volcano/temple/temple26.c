#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("神殿重地");
	set_long(
@LONG_DESCRIPTION
你现在位於神殿重地，四壁萧然，上面一扇天窗打的开开的，假如没啥事请快点离开。
一位矮灵族的长老正在这里闭关，他正在想怎麽样才能让火山停止爆发。
LONG_DESCRIPTION
	);
set( "exits", ([
     "north": OTEMP"temple25",
     ]) );
set_outside("eastland");
set("objects", ([
    "elder":OMONSTER"elder",
    ]) );
set("have_book",1);
set("wall_box_for_mar_short",1);    
reset();
}

int reset()
{
  set("have_book",1);
  ::reset();
}

void init()
{
  add_action("do_search","search");
}

int do_search(string arg)
{
  object me;
  
  me=this_player();
  
  if (!((me->query_temp("known_book_of_sword"))||(me->query_quest_level("Ohio's_brother"))))
    return 0;
  if (present("wraith elder",environment(me))) {
    tell_object(me,"矮灵族长老生气地挡在你面前阻止你继续搜索的行动搜索。\n");
    return 1;
  }
  tell_object(me,
 "你经过一番仔细的寻找，发现在墙壁上像一个像钥匙孔般特殊的暗洞(wall_hole)。\n");
  me->set_temp("can_insert_key",1); 
  return 1;
}
