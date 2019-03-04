#include "../oldcat.h"

inherit ROOM;

int showed;
void create()
{
	::create();
    set_short( "神殿走廊");
	set_long( 
@LONG
一条长长的走廊，一面壁画画出一位穿戴甲胄的矮灵族勇士骑著一不知名的野
兽，右手高举著长矛刺倒向他扑击的独角兽(unicorn)，往东可以通到右殿，往南可
通到正殿，往北可通向後院。
LONG
	);
set( "exits", ([
     "east" : OTEMP"temple20",
     "north" : OTEMP"temple12",
     "southwest" : OTEMP"temple6"
     ]) );
set( "item_desc", ([
     "unicorn":"@@look_unicorn",
     ]) );
reset();
}

string look_unicorn()
{
  object ob;

  if (present("unicorn",this_object()) || showed)
    return "一只正在和武士战斗的独角兽。\n";
  write("你看著这唯妙唯肖的独角兽............\n");
  write("看著看著，你发觉你和它的距离越来越近.........\n");
  write("你觉的不对劲，忙把眼睛闭起来.....再张开时，吓 ! 独角兽竟然在你面前。\n");
  ob=new(OMONSTER"unicorn");
  ob->move(this_object());
  showed=1;
  return "\n"; 
}

void reset()
{
  ::reset();
  showed=0;
}
