#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿内长廊");
	set_long( @LONG
这里是殿内长廊。廊道白玉铺地，栏杆雕饰精细，朱壁每尺镶嵌著拳大夜明珠
，好似一条蜿延银蛇，不时发出白光，照耀著满道通明。西边是天都大殿，琼槛瑶
阶，雕云缕月，气象庄严，奇丽无比；长廊往西南、北方向延伸。
LONG
	);
        set("light",1);
        set("exits" , ([
               "west" : SPALACE"e1",
              "north" : SPALACE"x2",
          "southeast" : SPALACE"x4",
        ]) );
	reset();
}
