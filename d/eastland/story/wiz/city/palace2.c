#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宫大殿入口");
	set_long( @LONG
你来到「巫咸城」人民的精神象徵皇宫里面。在你两旁各站著两个精神抖擞的
殿前禁卫，是负责宣诏外人觐见的。前面翡玉白阶镶著碗大的珍珠，前面不远处是
城主和文武官员讨论事情的地方，那里金光闪闪刺眼已极！
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "north" : SCITY"palace3",
              "out" : SCITY"palace1"
        ]) );
	reset();
}
