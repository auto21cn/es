#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("天台");
	set_long( @LONG
你正立足在一块小小的玉制椭圆形平台上，四周遍是绿油油的草地，天空无垠
的苍穹。在这天台旁有几尊刻工精美的白玉雕像，尊尊羽衣星冠，丰神俊郎，衣服
华美，栩栩如生望若神仙中人。遥望东边，一宫院金庭玉柱，瑶壁琼楼，富丽□皇
，气象万千，不可而语。在台下有阶梯通往东方草地上的一条小路。
LONG
	);
	set("light",1);
	set("can_use_flute",1);
        set( "exits", ([
            "steps" : SPALACE"plain2"
        ]) );
	reset();
}
