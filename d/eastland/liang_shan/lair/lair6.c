#include <../takeda.h>

inherit ROOM;

void create()
{
	object snake;
	::create();
	set_short( "魔法阵中" );
	set_long(@C_LONG
你进入了这个诡异的魔法阵，魔法阵的中心被层层的黑雾所包围，不过....
这是雾吗?你怀疑著,你能很清楚地看到一些悬浮粒子飘散在你的周围.
\或\许\是一种邪恶的物质,你能感觉到有著邪恶的成份参杂其中.
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"lair/lair5"
        ]) );
        snake = new(TMONSTER"snake");
        snake->move(this_object());
        reset();
}
int clean_up() { return 0; }
