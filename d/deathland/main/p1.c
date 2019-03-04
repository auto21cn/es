
#include "../echobomber.h"
inherit ROOM;

void create()
{
        ::create();
        set("light",1);
        set_short("黑暗沼泽");
        set_long(@Long_Description
一个充满奇怪植物的沼泽,你的脚似乎不能很顺利的移动.而那些奇怪的植物正伸
著它的触手到处寻找食物,这沼泽是一个非常危险的地方.
在北方悬崖有一个很深的洞穴(hole),但是你不确定他通向何处.
Long_Description
 );
  set("item_desc",([
      "cliff":"很高的悬崖.有很多的蔓□植物依附在上面.\n",
      "hole":"一个很深的洞穴.\n",
      "plants":"一些奇怪的植物.\n",
                     ]) );

  set("exits",([
    "southwest":Deathland"/main/d1",
   ]));
}

void init()
{
     add_action("to_enter","enter");
}

int to_enter(string str)
{
   if (!str||str!="hole") return 0;
 
   write( 
           "你掉入这深深的洞穴.\n");
   this_player()->move_player(Deathland"/main/d2.c",
      ({
      "%s掉入洞中而消失.\n",
        "%s从上面的洞中掉了下来.\n"}),"");
   return 1;

}
