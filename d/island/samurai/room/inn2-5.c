#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川楼二楼警卫室" );
   set_long(@ANGEL
在你来到千川楼二楼警卫室，这是随时都有人在此看守著，以防止
有人来行刺武士团队长，而看守的人也都是武士团里的精英，同时也是
对武士团绝对忠心武士．
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
	    "guard1":MOB"guard4",
	    "guard2":MOB"guard4"
	    ]));		
        set( "exits", ([
    "east"  :MR"inn2-4",
    "north" :MR"inn2-6"    
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

