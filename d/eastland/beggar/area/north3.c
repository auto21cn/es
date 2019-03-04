#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "north3", "村路" );
	set_long(@C_LONG
你现在正走在一条颇为宽大的村路上,约可容纳两匹马并行。村路向南、北方
向延伸。这条村路整理得蛮乾净的,路旁的植物修缉的很整齐,花儿欣欣向荣,比起
广场那片光秃秃的景像自是不可而语。毕竟这条是连接几个较大铺子,可说是村内
最繁华的道路。虽是如此, 却看不出任何人工刻意留下来的痕迹,这一定是出自於
某位名匠之手。东边有一栋建筑物,原来是『薪胆』客栈 ( wine shop )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
             "south":DBEGGAR"north2.c",
             "north":DBEGGAR"north5.c"
	]) );
        set("c_item_desc",([
             "wine shop":"一间三层高的房子,似乎可以进去看看 ( enter ) 。\n"
        ]) );
     reset();
}
void init()
{
    add_action("to_enter","enter");
}
int to_enter(string str)
{
    if (!str) return 0;
    if (str=="wine shop") {
       this_player()->move_player(DBEGGAR"wine_shop",({
           "%s进入了客栈里。\n",
           "%s从外面走了进来.\n"}),"");
       return 1;
    }
    else {
       write("你想进入那里?\n");
       return 1;
    }
}