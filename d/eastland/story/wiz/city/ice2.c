#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("冰原");
	set_long( @LONG
极目远眺是片无垠无涯，银光闪闪，通体晶莹，不见任何尘沙的冰原。在这片
坚滑光润的地面上，竟会生著许多不知名的奇树，每株七、八抱宽，其高多达一、
二丈以上，全身覆盖著一片冰衣，里面却是琼枝碧叶，青葱欲滴。另外在北边还有
一个隆出地面约六尺高的小冰丘。
LONG
	);
	set( "exits", ([ 
           "north" : SCITY"ice2",
           "south" : SCITY"ice1",
            "east" : SCITY"ice2",
            "west" : SCITY"ice2",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_enter","enter");
}
int do_search(string arg)
{
   if (arg!="cave") {
      write("你找了找，发现北边的冰丘竟然有一个小洞穴(cave)！\n");
      return 1;
   }
   write("这是一个尺宽的圆洞，如果你有胆量可以进去(enter cave)看看。\n");
   return 1;
}
int do_enter(string arg)
{
   if (!arg||arg!="cave")
     return notify_fail("你想要进去那里？\n");
   write("你进入北边冰丘的一个小洞穴里。\n");
   this_player()->move_player(SCITY"ihole1",({
       "%s进入了冰丘的一个小洞穴。\n",
       "%s从外面走了进来.\n"}),"");
   return 1;
}