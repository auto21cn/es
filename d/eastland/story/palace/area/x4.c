#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿内长廊");
	set_long( @LONG
这里是殿内长廊，长廊往西北方向延伸。廊道白玉铺地，栏杆雕饰精细，朱壁
每尺镶嵌著拳大夜明珠，好似一条蜿延银蛇，不时发出白光，照耀著满道通明。衔
接东方出口的是回廊，可以通往後花园。
LONG
	);
        set("light",1);
        set("exits" , ([
                "east" : SPALACE"garden1",
           "northwest" : SPALACE"e2",
        ]) );
	reset();
}
