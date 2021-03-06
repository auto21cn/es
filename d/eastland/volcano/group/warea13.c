#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮灵族部落");
	set_long( 
@LONG_DESCRIPTION
这里是矮灵族部落群，西南边可通到广场，这里的建筑物大都是石造的，少数人
住帐蓬，地上用很多石板铺成的路贯穿整个部落，整个部落给人的感觉是非常宁静且
安详的，由於火山已经有很多年没有爆发了，因此新一代的族人也慢慢的就淡忘了此
事，一栋石造房子(house)矗立在这儿。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : OGROUP"warea10",
     ]) );
set( "objects", ([
     "wguard":OMONSTER"wguard",
     ]) );
set("item_desc", ([
    "house": "一栋石造的房子，看起来是呈黑红色的，还有个火龙的雕饰在房屋的屋顶，不知道\n是谁住在这里？\n",
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
  if (!arg || arg!="house" ) {
    write("你要进去那里？\n");
    return 1;
  }
  tell_object(this_player(),"你走进这间房子里\n");
  tell_room(this_object(),"你见到"+this_player()->query("c_name")+"走进房子里。\n",this_player());
  this_player()->move_player(OGROUP"house4","SNEAK");
  return 1;
}
