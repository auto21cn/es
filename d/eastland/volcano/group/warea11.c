#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮灵族部落");
	set_long( 
@LONG_DESCRIPTION
这里是矮灵族部落群，西北边可通到广场，这里的建筑物大都是石造的，少数人
住帐蓬，地上用很多石板铺成的路贯穿整个部落，整个部落给人的感觉是非常宁静且
安详的，由於火山已经有很多年没有爆发了，因此新一代的族人也慢慢的就淡忘了此
事，你可以看到有一个帐篷(camp)在你的前方。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest":OGROUP"warea10",
     "east" : OGROUP"warea16" ]) );
set("objects", ([
    "wboy":OMONSTER"wboy",
    ]) );
set("item_desc", ([
   "camp" : "一个画满奇怪符号的帐篷，不知道是谁住在里面，你想进去瞧瞧吗?\n",
   ]) );
set_outside("eastland");
reset();
}

void init()
{
   add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="camp" ) {
    write("你要进去那里？\n");
    return 1;
  }
  tell_object(this_player(),"你走进这帐篷里\n");
  tell_room(this_object(),"你见到"+this_player()->query("c_name")+"走进帐篷内。\n",this_player());
  this_player()->move_player(OGROUP"house3","SNEAK");
  return 1;
}
