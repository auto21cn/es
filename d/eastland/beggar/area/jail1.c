#include "../dony.h"
inherit DOORS;
inherit ROOM;

void create()
{
	::create();
        set_short( "jail1", "『薪胆村』监牢" );
	set_long(@C_LONG
你现在进入了一间臭到极点的监牢，到底有多臭你也说不上来，因为你的手正
不自觉地捂著鼻子。地上有几具还没有腐败完的□体和许多白森森的骨头, 监牢的
角落里有一张钉在墙壁上的木板床。
C_LONG
	);
	set( "light" , 1 );
	set( "exits", ([
                      "east":DBEGGAR"east10.c"
	]) );
        set( "c_item_desc", ([
                 "bed" :"一张简简单单的木床。\n",
                 "bone":"几根死人的骨头。\n"
        ]) );
                                    
        set( "objects",([  
                     "chan":DMONSTER"chan"
                     ]) );
      
        create_door( "east", "west", ([
                     "keyword" : ({ "copper door", "door" }),
                     "name" : "copper door",
                     "c_name" : "小铜门",
                     "c_desc" : "一扇很普通的小铜门",
                     "status" : "locked",
                     "lock" : "DBEGGAR_JAIL1"
                    ]) );
     reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
   if( !arg || arg!= "bone" )
      return notify_fail("你要找什麽呢?\n");
         
   tell_object(this_player(),"你心里想,原来是有暗门。\n");
   this_player()->move_player(DBEGGAR"jail2.c");
   return 1;
}      
