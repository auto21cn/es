#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川楼前庭" );
   set_long(@ANGEL
这里是千川楼前庭，道路的两旁种了一堆你从来都没有看过的花，虽
然你没看过，但是你知道那一定是一些高贵的品种，而路面是用这里的特
产流晶岩做的，看起来闪闪发亮，让人误以为是用金子铺成的．
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "south" :MR"inn01",
    "north" :MR"inn03"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

