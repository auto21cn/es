#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("渔村道路");
        set_long( 
@LONG
你正走在渔村的道路上，迎面扑来的是一股浓浓的腥臭味；在地上，纵横交错
著血水枯乾的小河；一团团苍蝇，正汲汲於腐烂的鱼肉上，不时发出嗡嗡地鸣声。
晦暗不明的天空，乌云团簇好似一只只正在张牙舞爪的野兽，野兽正恶狠狠地瞪著
你，好像对著你说：『快来吧，快来吧，我的食物』。西边有间茅屋，北和东边是
渔市场。
LONG);
    set( "exits", ([
         "south":LAKE"village17"
    ]) );
    set("objects", ([
       "merchant#1":LMONSTER"merchant",
       "merchant#2":LMONSTER"merchant",
       "merchant#3":LMONSTER"merchant",
    ]) );
    ::reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
       return notify_fail("你要进入那里?\n");
   this_player()->move_player(LAKE"house18",({
       "%s进入了一间小茅屋。\n",
       "%s从外面走了进来.\n"}),"");
   return 1;
}