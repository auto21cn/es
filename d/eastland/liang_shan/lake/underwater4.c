#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
	set_short( "湖底" );
	set_long(@C_LONG
这里是大湖的湖底，从水面上透入淡淡的天光，摇曳的光影投影在平坦的沙底
，形成了一幅奇特的情景。从水底向上仰望，隐约可以看到水面上的风景，平沙上
躺著几节枯\木\，造型奇特，但你却没有时间好好欣赏。因为你知道，不赶快离开此
处的话，你就要永远的躺在湖底了。
C_LONG
	);
	set( "exits", ([
             "up" : TROOM"deep4",            
	     "south" : TROOM"underwater6",
	     "north" : TROOM"whirl1",
	     "east" : TROOM"underwater5"
	]) );
        set( "objects",([
             "fish1" : TMONSTER"fish3",
             "fish2" : TMONSTER"fish4"]));
        set_outside("eastland");
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



