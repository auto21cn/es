#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿内长廊");
	set_long( @LONG
这里是殿内长廊，长廊往这个方向已经是尽头了。廊道白玉铺地，栏杆雕饰精
细，朱壁每尺镶嵌著拳大夜明珠，好似一条蜿延银蛇，不时发出白光，照耀著满道
通明。
LONG
	);
        set("light",1);
        set("exits" , ([
           "south" : SPALACE"e2",
        ]) );
	reset();
}
