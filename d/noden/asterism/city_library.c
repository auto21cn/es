// File: /d/noden/asterism/city_library.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("图书馆");
	set_long(
		@C_LONG_DESCRIPTION
这里有一栋雄伟的大建筑物,是艾斯特律恩(asterism)城的图书馆,大部份的书籍都
在地精魔族战争中被烧的残缺不全了.但是仍有一些有价值的书籍被保存了下来.或许你
能找到隐藏其中的秘密.往北你将回到花园,而南边是一座很高的塔.
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["tower":"一座建筑的很宏伟的高塔.\n"]));       
	set( "exits", ([ 
		"north":ASTR"city_garden",
		]) );
	reset();
}                         

void init()
{
   add_action("to_enter","enter");
   }
   
   int to_enter(string str)
   {
       if (!str)
        return notify_fail("进去哪儿啊?\n");
       if (str=="tower")      
          {
            write("你进入了塔中.\n");
               this_player()->move_player(ASTR"tower3-1",({
                     "%s进入了塔中.\n","%s从外面进来.\n",}),"");
             return 1;
           }
      
       if (str=="library")      
          {
            write("你进入了图书馆.\n");
               this_player()->move_player(ASTR"lib01",({
                     "%s进入了图书馆.\n","%s从外面进来.\n",}),"");
             return 1;      
           }
        return notify_fail("进去哪儿啊?\n");  
  
    }  
