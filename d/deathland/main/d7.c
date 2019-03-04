
#include "../echobomber.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set("light",1);
       set("short","一个很深的洞穴");

       set("long",@Clong
当你来到这个地方时,你发现东边的岩壁上有一个石门(stone door),而且
门上有一个板子(board),西边则是一个很大的洞穴,北方是一个斜坡,通往未知
的深处,而南边是一个往上的洞穴.风从地底不停地吹上来,你觉得越来越冷了.
Clong
          );
set ("item_desc",([
"board":@Board
 ---------------------------------------------------------------------
       这是通往矮人国度的入口,假如你愿意帮助我们对抗邪恶的山顶巨人的
       话,欢迎你,我的朋友.
                         --皇家侍卫队长 卡尔服德(Calford)
---------------------------------------------------------------------
Board
 ]));
 set("exits",(["southup":Deathland"/main/d3",
               "west":Deathland"/troll/cave_01",
               "east":Deathland"/city/c1",
               "northdown":Deathland"/main/d8",
              ]) );
create_door("east","west",([
             "keyword" : ({"stone door","door" }),
             "status" : "closed",
             "c_desc" : "一扇结实厚重的石门",
             "c_name" : "石门",
             "name":"stone door",
             "desc":"a stone door"
              ]) );
reset();
}
