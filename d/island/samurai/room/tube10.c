#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "忍者屋" );
   set_long(@ANGEL
你来到一个忍者屋，你现在终於知道是什麽人住在地下了，原来是武士城堡
的另一之部队忍者们住在下面，因为是在地下，所墙壁上有好几颗夜明珠摆著用
来照明，而旁边放了几个当作练习靶的假人，还有一阵微风吹著，你可以确定附
近一定有出口．    
ANGEL
   
         );
         
	set( "light",1);
	set("objects",([
	"ninja1":MOB"ninja",
	"ninja2":MOB"ninja"
	             ]));
        set( "exits", ([
                "west":MR"tube09",
                "south" :MR"tube11"
                ]) );
         reset();                     
#include <replace_room.h>
}

