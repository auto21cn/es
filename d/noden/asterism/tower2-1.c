// File: /d/noden/asterism/tower2-1.c 
//                              by Indra in Eastern Story

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的底层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中矮人高塔的底层,一阵肃杀的气氛笼罩与此地.这里的防护
十分强大,除了有著守卫看守著之外,这高塔的每一层都用上了厚厚的锁 ,以防止外人
进入.
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"out" : ASTR"city14",
		"up"  : ASTR"tower2-2",
		"down": ASTR"tower2-0",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard#1":MOB"dwarf_guard01",
	    "guard#2":MOB"dwarf_guard01",
	    ]) );
	reset();
}

int to_up()
{
   if (present("guard")) 
      {
      if((string)this_player()->query("race")=="dwarf")
         { 
           if( ((int)this_player()->query_level())<15 ) return 0 ;
      
           write(
                    "守卫把你挡了下来.\n"
                    "守卫说:你这乳臭未乾的小子想上去干嘛 ? 回家吸奶吗 ?\n"
                      );
           tell_room( this_object(),
                    "守卫把"+this_player()->query("c_name")+"挡了下来.\n"
                    " 守卫说:你这乳臭未乾的小子想上去干嘛 ? 回家吸奶吗 ?.\n"
                     ,this_player());
           return 1 ;
         }
      write(
      "守卫把你挡了下来.\n"
      "守卫说:往上走的唯一方法是踏著我的尸体上去.\n");
      tell_room( environment(this_object()),
                 "守卫把"+this_player()->query("c_name")+"挡了下来.\n"
                 "守卫说:往上走的唯一方法是踏著我的尸体上去.\n"
                              ,this_player());
     return 1;
    }
   return 0 ;   
}
