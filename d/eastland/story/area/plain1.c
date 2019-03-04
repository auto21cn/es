#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草原");
	set_long(@LONG
你来到了一处空旷的草原，东和北边是草原的延伸而南边是大树群。在草原上
长满了些小小的矮花，矮花的颜色很鲜□，靠近一闻，鼻子中满是浓郁的香味。除
此之外，一群野蜂正悠哉悠哉地穿梭在花丛间，恣意地采著蜂蜜。另外在你西边长
满了高及头顶的植物，里面不时传来野兽的叫声，那声音令你感到毛骨悚然，你心
里想想，最好还是不要往那边走去，以免发生危险。
LONG
	);
	set("light",1);
	set("exits", ([ 
            "east" : SAREA"plain2",
            "west" : SAREA"coast6",
           "north" : SAREA"plain3"
        ]) );
	reset();
}
