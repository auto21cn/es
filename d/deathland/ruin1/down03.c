
// Deathland/ruin1/down03.c

#include "../echobomber.h"

inherit DOORS;
inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹地下储藏室");
     set_long(@Long
Long
,@CLong
这里是遗迹的地下储藏室 ,似乎是用来放置饮水与食物的地方 .这里的地上与前
面的地方不同 ,十分乾净 .\或\许\这地方是储藏室吧 .但是这个地方却有一种令人毛骨
悚然的感觉 .
CLong
);
     set("objects",([
         "wight":Monster"/wight02",
         ]) );
     
     set("exits",([
         "north":Deathland"/ruin1/down02",
         ]) );
     create_door("north","south",([
             "name":"stone door",
             "c_name":"石门",
             "keyword":({"stone door","door",}),
             "c_desc":"石门",
             "status":"closed",
             "desc":"a stone door",
                     ]) );    
     ::reset();
}

void init()
{
    this_player()->set_explore("deathland#18");
}
