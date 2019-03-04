
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set("light",1);
set_short("The road toward the sleeping hall","通道");
  set_long(@Long
Long
,@CLong
连接大厅与起居室的通道.通道两旁的墙壁分别挂著现任矮人国王莫拉德五世
(Molader V)以及他死去的大儿子法拉第的画像(icons).
CLong
);

set("c_item_desc",([
    "icons":"莫拉德五世看起来一副和蔼可亲的样子,而法拉第看起来则像是你的"
            "老朋友.\n"         
    ]) );    
set("search_desc",([
     "icons": "@@to_search_icons",
     "icon": "@@to_search_icons",
     ]) );    
set("exits",([
               "west":Deathland"/palace/pa_01",
               "east":Deathland"/palace/pa_05",
             ]));
::reset();
}

int to_search_icons()
{
     write("你发现有一个通道藏在画像後,於是你便钻进去里面一探究竟。\n");
     this_player()->set_explore( "deathland#10" );
     this_player()->move_player(Deathland"/palace/pa_0b","SNEAK");
     return 1;
}
