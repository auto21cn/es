
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("深渊南方");
set("long",@Long_description
从这往北看去,有一个非常大,又非常深的深渊横在你的面前,似乎让人觉得它就
是通往地狱的入口.这里有三个帐篷(tents),而三个帐篷中有一堆营火(campfire)放
置著
Long_description
	);
set("exits",(["west":Deathland"/main/d9",
              ]));
set("item_desc",([
    "campfire":"一堆已被熄灭的营火.\n",
    "tents":"三个很大的帐蓬,其中一个帐蓬是敞开的,好像正欢迎著每个人进入那里.\n"
               ]) );

}

void init()
{
 add_action("to_enter","enter");

}

int to_enter(string str)
{
    if (!str||str!="tent") return 0;
    this_player()->move_player(Deathland"/main/shop",({
    "%s进入了帐蓬.\n",
    "%s从外面走了进来.\n"}),"");
    write("你好像走进了一间商店.\n");
    return 1;
}
