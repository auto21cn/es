
#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("井边");
        set_long( 
@LONG
这口水井 (well) 是渔村日常生活赖以为生的水源地，平时，村里都会派人来
巡视一番，并且定期做维修的工作，以免水井受到污染。所以，这口井看起来虽然
老旧，依然保持著乾净的供水。井旁边不时有妇女在洗服，话东家长聊西家短的，
说不定你可以从其中打听到什麽重要的消息也说不定。道路往东、北边延申；南、
西边是一面墙。
LONG);
    set( "light",1);
    set("exits",([
       "north":LAKE"village10",
        "east":LAKE"village11"
    ]) );   
    set("c_item_desc",([
      "well":"一口清澈的水井，令你有股想跳下去 (jump) 的冲动。\n",
    ]) );         
    set("objects",([
       "woman#1":LMONSTER"woman",
       "woman#2":LMONSTER"woman",
       "woman#3":LMONSTER"woman",
    ]) );
    ::reset();
}
void init()
{
    add_action("do_jump","jump");
}
int do_jump(string arg)
{
    if ( ! arg || arg !="well" )
       return 0;
    write("你毫不犹豫地脱光服往井一跳!\n\n只见井底一股吸力把你卷往下面 ...\n\n\n");
    this_player()->move_player(LAKE"village5",({
       "%s脱光衣服往井一跳 。\n",
       "%s从底下的池水浮上来.\n"}),"");
    return 1;
}