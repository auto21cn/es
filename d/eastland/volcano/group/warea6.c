#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮灵族部落");
    set_long( 
@LONG_DESCRIPTION
这里是矮灵族部落群，西南边可以通到出口，南边可通到广场，这里的建筑物大都是
石造的，少数人住帐蓬，地上用很多石板铺成的路贯穿整个部落，整个部落给人的感
觉是非常宁静且安详的，由於火山已经有很多年没有爆发了，因此新一代的族人也慢
慢的就淡忘了此事，你可以看到有一个帐篷(camp)在你的右手边。
LONG_DESCRIPTION
	);
set( "exits", ([
     "southwest" : OGROUP"warea3",
     "south" : OGROUP"warea9" ]) );
set( "objects", ([
     "wgirl":OMONSTER"wgirl",
     ]) );
set("item_desc", ([
    "camp" : "一个用兽皮缝制而成的帐篷，帐篷上还有一些花花绿绿的装饰品，从缝制的痕迹\n来看，矮灵族的手工也蛮不错的，你心里在猜这□可能是女孩子住的地方。\n",
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
  if (!arg || arg!="camp") {
    write("你要进去那里？\n");
    return 1;
  }
  tell_object(this_player(),"你走进这帐篷里\n");
  tell_room(this_object(),"你看到"+this_player()->query("c_name")+"走进帐篷内。\n",this_player());
  this_player()->move_player(OGROUP"house2","SNEAK");
  return 1;
}
