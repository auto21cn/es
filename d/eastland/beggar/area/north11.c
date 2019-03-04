#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "north11", "村路" );
	set_long(@C_LONG
你现在正走在一条由碎石子铺成的村路上,村路延申到这里似乎已到尽头。村
路不很大,约可容纳一匹马行驶的宽度。在路旁长著一些奇形怪状的植物 ,那上面
更开著许多不知名的小花,小花闻起来有点淡淡的香味, 那味道说不出的使得你心
旷神怡。鸟语蛙呜, 顿时你烦恼尽失,站在这里真是有如仙境。你西边是一大片竹
林,而东边有一栋白色的建筑物 ( building ) 原来是『赏善罚恶厅』。
C_LONG
	);
        set_outside("noden");
        set( "exit_suppress", ({
                        "west" }) );
	set( "exits", ([
               "north":DBEGGAR"north10.c",
	        "west":DBEGGAR"forest1.c"
	]) );
        set("c_item_desc",([
               "building":"一栋白色的建筑物,建筑物的前面有两只石狮子。\n"
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
    if (str=="building") {
        this_player()->move_player(DBEGGAR"master_room",({
            "%s进入了一间矮矮的房子。\n",
            "%s从外面走了进来.\n"}),"");
        return 1;
    }
    else {
        write("你想进入那里呢?\n");
        return 1;
    }
}    