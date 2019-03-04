#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("天都大殿北侧");
	set_long( @LONG
你立足之地是天都大殿的北侧，大殿地面原是用整片翠精碧玉建成的，玉质特
佳，光明若镜，毛发可鉴。环顾殿内，琉璃天瓦，上下两相对照，发出七彩绚丽灿
光；殿偏玉柱彩绘，朱壁雕楼，除此之外别无它物，虽然空间广阔，却益发显得庄
严隆重，气象万千，不可而语。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"n1e1",
           "west" : SPALACE"n1w1",
          "north" : SPALACE"n2",
          "south" : SPALACE"center",
        ]) );
	reset();
}
