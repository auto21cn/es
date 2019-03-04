#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("城中心道路");
	set_long( @LONG
这里是「巫咸国」的中心道路，同时也是达官贵人居住的地方。地是用玉做的
，并且在玉上还雕刻著龙凤之类的祥瑞动物，把北边一座座气派豪华的建筑物衬托
的更加富丽堂皇。另外在南边的路旁还建造一个喷水池，其雕工精美，不亚於地上
所刻的动物。西边是城中心，东边是东大路。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"en1",
       	    "west" : SCITY"center",
           "north" : SCITY"house1"
        ]) );
	reset();
}
