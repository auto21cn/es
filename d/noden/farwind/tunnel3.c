//#pragma save_binary
 
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
	::create();
    set_short("地穴");
	set_long( @C_LONG_DESCRIPTION
你来到一个比较宽敞的地穴，洞穴顶部不断地有水滴滴下来，在地上滴出
一个小水池( pool )，你注意到水池旁边有几个小土堆，其中一个土堆旁边吓
然躺著一具白骨( skeleton )。
C_LONG_DESCRIPTION
	);
 
	set( "exits", ([
		"northeast" : "/d/noden/farwind/tunnel2.c",
	]) );
   set( "item_desc", ([
	"pool" : "一个相当浅的小水池, 里面似乎有些东西。\n",
	"skeleton" : "一具相当残破的枯骨, 它的手骨似乎正指向水池。\n",
	]) );

        set("search_desc",([
                     "pool" : "@@to_search_pool"
                  ]));

	set( "objects", ([
		"crazy rat" : "/d/noden/farwind/monster/crazy_rat"
	]) );
	reset();
}

void init()
{
	if( this_player() ) this_player()->set_explore( "noden#2" );
}

int to_search_pool()
{
   if( present("crazy rat",this_object()) )
   {
	write( "先把疯老鼠赶走吧!\n" );
	return 1;
   }
  write("你靠近水边，不小心一脚采下去！哎～～\n");
  this_player()->move_player("/d/noden/drow/r41","SNEAK");
  return 1;
}
