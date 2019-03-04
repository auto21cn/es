#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "拍卖广播网播音室" );
	set_long(@C_LONG
这里就是著名的拍卖广播网的播音室，不是很大的一个房间被一面晶莹
剔透的魔法水晶墙分割成两半，墙的那边有几名年轻貌美的女郎正聚精会神
地运用魔法水晶的法力主持著拍卖的进行，墙的这边却堆满了等待拍卖的东
西和一些奇形怪状的魔法道具，显得十分杂乱。
C_LONG
	);
	set( "light",1 );
	set( "objects", ([
      	        "guardian" : "/d/noden/farwind/monster/auc_guard"
        ]) );
	set( "exits", ([
                "north" : "/d/noden/farwind/bazz2",
        ]) );
	
	reset();
}
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	tell_object(this_player(),
	"你伸出手来，可是发觉一切的东西似乎都十分沈重，彷佛被吸住了一般。\n");
	return 1;
}
int clean_up() { return 0; }
