#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("城中心");
	set_long( @LONG
你站足之地是「巫咸国」的中心点，地上是用玉做的，并且在其上还雕刻著龙
凤之类的祥瑞动物。在城中心的旁边还摆著一座高八尺的金铸雕像，那雕像，栩栩
如生，一看就知道是经过行家之手，否则不会如此生动细腻。北边是皇宫大道，南
边本来是城里最主要的道路，不晓得为什麽，被封闭起来。在路旁还有一块黑色大
石(stone)。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"ne1",
            "west" : SCITY"nw1",
           "north" : SCITY"palace1"
        ]) );
        set( "c_item_desc", ([
                  "stone" : @LONG
一颗有著纯黑色的大石，石头上写著黑色代表黑暗的意思，上面有被摸过(touch)的痕迹。
LONG
        ]) );
	reset();
}
void init()
{
   add_action("do_worship","worship");
   add_action("do_touch","touch");
}
int do_touch(string arg)
{
   if ( !arg || arg !="stone" )
       return notify_fail("你要摸什麽东西？\n");
   write("\n你好奇地摸一摸这块黑色的大石，只见一道黑色的光线贯穿你的身子！\n\n\n");
   this_player()->move_player("/d/deathland/city/c1",({
       "%s的身子被一道黑色的光线贯穿！\n",
       "%s借著一道黑色来到了这里.\n"}),"");
   write("\n在黑光之後，你被带到了黑暗大陆。\n");
   return 1;
}
int do_worship()
{
    tell_object(this_player(),
       "你双手合什，跪在地上向雕像虔诚地膜拜，希望今年能够发大财。\n");
    this_player()->save_me();
       "/adm/daemons/backup"->user_backup(this_player());
    return 1;
}