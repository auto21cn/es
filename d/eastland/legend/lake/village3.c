#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "古木小径" );
    set_long(@C_LONG
你来到了一条古木小径的尽头。小径的两旁有一排排不知名的树木，树枝挡住
了阳光，显得有些阴凉，树上一些鸟儿正啾啾地叫著。在你西边有一间小木屋。
C_LONG
    );
    set( "light",1);
    set("c_item_desc",([
     "house":"一间用绘木做成的屋子，你可以进去看看 ( enter )。\n"
    ]) );
    set( "exits", ([
     "south":LAKE"village2"
    ]) );
    reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
       return notify_fail("你要进入那里?\n");
   this_player()->move_player(LAKE"house1",({
      "%s进入了一间小木屋。\n",
      "%s从外面走了进来.\n"}),"");
   return 1;
}