#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the stranger place","一个奇怪的地方");
  set_long(@Long
Long
,@CLong
一个奇怪的地方,你的思考忽然顿了一下..........
一个奇怪的洞口出现在井壁边,你可以继续往上爬,\或\是进去洞口看一看.
但是一股邪气从洞口发出......
CLong
);
set( "c_item_desc",([
     "hole":"一个很奇怪的洞,似乎危险与死亡正在里面等著你.\n"
     ]) );
  
set( "exits",([
             "down":Deathland"/dwarf/well01",
             ]));

}

void init()
{
   add_action("to_climb","climb");
   add_action("to_enter","enter");
}

int to_climb()
{
    this_player()->move_player(Deathland"/dwarf/village_07",({
      "%s继续往上爬.\n",
      "%s 从井里爬了出来.\n",
      }) ); 
    return 1;
}

int to_enter(string str)
{
   if (!str||str!="hole") return 0;
    
   this_player()->set_explore( "deathland#16" ); 
   this_player()->move_player(Deathland"/dwarf/village_0a",({
      "%s进入了那个邪恶的洞口.\n",
      "%s从外面进来.\n",
       }) );
    return 1;
    
} 
