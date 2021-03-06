// File: /d/noden/asterism/tower3-1.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地精高塔的底层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中地精高塔的底层。矮人和半身人为这片土地本来的
主人建筑了这麽一座外观宏伟的住所。这儿四周的墙璧,被各式各色的宝石镶点
得五彩缤纷。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"out" : ASTR"city_library",
		"up"  : ASTR"tower3-2",
		"down": ASTR"tower3-0",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard#1":MOB"gnome_guard",
	    "guard#2":MOB"gnome_guard",
	    ]) );
	reset();
}

int to_up()
{
  if (present("guard")&&(string)this_player()->query("race")=="daemon") 
    {
      write(
           "守卫把你挡了下来.\n"
            "守卫说:喂!魔族的。你当这里是公园,想逛哪就去哪吗?\n"
           "\n");
      tell_room( this_object(),
                 "守卫把"+this_player()->query("c_name")+"挡了下来.\n"
                 "守卫说:喂!魔族的。你当这里是公园,想逛哪就去哪吗?\n"
                  , this_player());
     return 1;
     }
   return 0;   
}
