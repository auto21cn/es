#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川楼一楼" );
   set_long(@ANGEL
在你来到千川楼一楼，其内部的装潢都是名家精心设计的，不管是支撑
的梁柱，还是照明的灯具，都是用上等的建材加上工匠们全心全意的雕塑所
制成的，地板则是用高级的木材做成的，走起来和外面的石头路面有著不一
样的感受，空气中还飘有一股黑檀木的香气．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "east"  :MR"inn06",    
    "south" :MR"inn03",
    "north" :MR"inn05"
                ]) );
      create_door("south","north",([
                  "keyword" : ({"door","ebony door"}),
                  "status"  : "closed",
                  "name"    : "Ebony Door",
                  "c_name"  : "黑檀木门",
                  "c_desc"  : "一个用黑檀木做门，上面用精细的手工\n"
                              "雕出一条华丽的龙\n"
                  ]) );
                            
         reset();                     
}

