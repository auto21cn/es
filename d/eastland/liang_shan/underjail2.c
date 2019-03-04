#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "长长的岩隙" );
	set_long(
	"这是在山间自然生成的岩隙，两旁紧迫的山璧使你有一种透不过气的感觉，\n"
	"一条条的钟乳从你的头顶垂下，虽然你一方面赞叹大自然的鬼斧神工，另一\n"
	"方面你却又暗自咒骂它们使你的通行更加困难。再加上地上湿漉漉的，你必\n"
	"须更小心的前进以免滑倒。\n"
	);
        set( "exits", ([
                "southeast" : TROOM"underjail3"
        ]) );
        reset();
}
int clean_up() { return 0; }
