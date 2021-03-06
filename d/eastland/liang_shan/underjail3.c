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
	"须更小心的前进以免滑倒。岩隙的尽头有个小洞，好像可以离开此处。\n"
	);
        set("c_item_desc",(["hole":
        "一个小洞，可以通到外面去，假使你不太胖的话，应该可以挤(squeeze)\n"
        "的出去，不过这个洞蛮长的，因此你无法得知外面的环境如何。 \n"
                ]));
        set( "exits", ([
                   "squeeze" : TROOM"underjail4",
                   "northwest" : TROOM"underjail2"
                   ]));
        set("exit_suppress", ({ "squeeze" }) );                 
        set("pre_exit_func",([
            "squeeze":"pass_hole",
                ]) );
        reset();
}
int pass_hole()
{
    write("你把头伸进小洞，挤呀挤呀，终於给你挤出去了....\n");
    write("碰的一声....你重重的摔在地上\n");
    this_player()->receive_damage(10);
    return 0;
}
int clean_up() { return 0; }