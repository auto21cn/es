#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "west9", "村路" );
	set_long(@C_LONG
你现在正走在一条由碎石子铺成的村路上,村路延申到这里似乎已是尽头。村
路不很大,约可容纳一匹马行驶的宽度。在路旁长著一些奇形怪状的植物 ,那上面
更开著许多不知名的小花,小花闻起来有点淡淡的香味, 那味道说不出的使得你心
旷神怡。鸟语蛙呜, 顿时你烦恼尽失,站在这里真是有如仙境。西边是一大片的竹
林,而南边的竹林再过去是一些矮矮的小山丘。你的东边有一间小房子( house )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                        "north":DBEGGAR"west7.c"	              
	]) );
        set("c_item_desc",([
               "house":"一间用砖头做的房子,似乎可以进去看看 ( enter ) 。\n"
        ]) );
        ::reset();
}
void init()
{
     add_action("to_enter","enter");
}
int to_enter(string str)
{
     if (!str) return 0;
     if (str=="house") {
        this_player()->move_player(DBEGGAR"vice_master_room",({
              "%s进入了一间砖做的房子。\n",
              "%s从外面走了进来.\n"}),"");
        return 1;
     }
     else {
        write("你想进入那里?\n");
        return 1;
     }
}      