// p1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("卡榭布兰卡宫．正殿");
    set_long(@C_LONG
映入你眼帘的是一个宽敞幽静的大厅。地板是由闪闪发亮的紫水晶与蓝宝
石铺设而成，四周的墙壁和天花板上满布著美丽的壁画和精致的石雕。女王的
王座端正地立於北边的台阶上，周围有著神奇的魔法力量拱卫著。
C_LONG
	    );
    set("exits", ([
	"south" : AREA"p0"
	]));
    set("objects", ([
	"queen" : MOB"queen",
	"emerald" : MOB"emerald"
	]));
    reset();
}


