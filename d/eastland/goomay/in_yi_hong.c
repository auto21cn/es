#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_short( "地洞" );
        set_long(
@LONG
你跌进一个奇怪的地洞，弯弯曲曲的地道刚好将你送到洞底，你只
感到有些头昏，却没有受伤，在这个空无一物的大土洞里，即使是点著
火把也是模糊一片，等等 ...洞的那一侧有两点微微的亮光，就好像是
野兽的眼睛一样，你最好小心一点。
LONG
        );
        
        set( "exits", ([ 
		"out" : Goomay"yi_hong",
        ]) );
        
        set( "objects", ([
                "roger" : Mob"roger",
        ]) );
        reset();
}
void init()
{
        if(this_player()) this_player()->set_explore("eastland#14");
}
