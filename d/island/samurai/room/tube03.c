#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "地下水道" );
   set_long(@ANGEL
你来到一个地下水道，虽然是在地下，但空气却是很清新，让你不会
有气闷的感觉，而且你发现这里地上蛮乾净的，似乎有人居住在里面，你
突然有一种奇怪的感觉，觉得这里墙壁(wall)和其他地方不一样．    
ANGEL
   
         );
	set( "light",0);
	set("item_desc",([
	"wall":"一个颜色很灰暗的墙壁，上面有几道刮痕\n"
	]));
	set("search_desc",([
	"wall":"@@to_search_wall"
	]));
        set( "exits", ([
                "east" :MR"tube02"
                ]) );
         reset();                     
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if(!arg || arg!="gate")
       return notify_fail("你要进去哪里?\n");
   write("你小心翼翼的走入这个通道，发现里面居然有个房间\n");
   this_player()->move_player(MR"tube04","SNEAK");
   return 1;
}       

string to_search_wall()
{
         this_player()->set_explore("island#12");
  return "当你仔细搜索墙壁时，发现里面隐藏著一个通道(gate)\n"
         "你可以试著进入(enter)\n";
}            
