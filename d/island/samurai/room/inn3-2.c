#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士团队长室" );
   set_long(@ANGEL
这里是武士团队长的住所，约修通常都在这里思考武士团的大小事
务，除了约修外，其他人是一律不准进入三楼的，所以约修可以在此安
静的好好思考及休息．
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"ya_shu":MOB"ya_shu"
	]));		
        set( "exits", ([    
    "south" :MR"inn3-1",
                ]) );
                            
         reset();                     
}

