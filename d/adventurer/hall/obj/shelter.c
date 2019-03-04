#include "mudlib.h"

inherit CONTAINER;

void create()
{
	object obj1;
	::create();
	set_name("shelf", "书架");
	set_short("书架");
	set("id", ({"shelf"}) );
	set_c_open_long(@C_LONG
这是一个巨大的黑檀木书架，上面放了许许多多的书，有些满布灰
尘，看来它们摆在这里已有相当久的时间了。除了书以外，不少粗
心的冒险者常常在进来查询资料後，把行李遗忘在书架上。
C_LONG
	);
	
	set("prevent_get",1);
	set("max_load",2000);
	obj1 = new( "/d/adventurer/hall/obj/letter1" );
	obj1->move( this_object() );
}
void init()
{
      ::init();
      container::init();
      add_action("do_get","get");
}
int do_get(string str)
{
     string s1,s2;
     if (!str) {
         write(
             "要拿什麽?\n");
             return 1;
             }
         sscanf(str, "%s from %s", s1, s2);
         if ((!s2) || (lower_case(s2) != "shelf")) return 0;
         
         if ( this_player()->query("class") == "adventurer" )
             return 0;
          
         if ( !present("avery",environment(this_object())) ) return 0; 
          
         write("艾佛瑞推了你一把，骂道: 你想干嘛啊，当我死了吗?\n");
         return 1;
}                
