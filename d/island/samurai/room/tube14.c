#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "忍者屋" );
   set_long(@ANGEL
你来到一个忍者屋，你现在终於知道是什麽人住在地下了，原来是武士城堡
的另一之部队忍者们住在下面，因为是在地下，所墙壁上有好几颗夜明珠摆著用
来照明，这里的空间比外面通道大了很多，所以你感觉也较舒服，而奇怪的是这
里的地板有很多大大小小的坑洞，好像有人在这练习一些奇怪的招式．
ANGEL
   
         );
         
	set( "light",1);
	set("objects",([
	"calford":MOB"calford",
	"poppy"  :MOB"poppy"
	             ]));
        set( "exits", ([
                "east":MR"tube15",
                "south" :MR"tube13"
                ]) );
         reset();                     
}

