#include "../../story.h"

inherit SPALACE"RR";
inherit DOORS;
void create()
{
        ::create();
	set_short("天都大殿西侧");
	set_long( @LONG
你立足之地是天都大殿的西侧，大殿地面原是用整片翠精碧玉建成的，不但玉
质特佳，光明若镜，毛发可鉴。环顾殿内，琉璃天瓦，上下两相对照，发出七彩旋
转虹光；殿偏玉柱彩壁，左侧一金门矗立，除此之外别无它物，虽然空间广阔，却
益发显得庄严隆重，气象万千。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"center",
           "west" : SPALACE"palace1",
          "north" : SPALACE"n1w1",
          "south" : SPALACE"s1w1",
        ]) );
        create_door( "west","east" ,([
          "keyword" : ({ "jade door", "door" }),
          "name" : "jade door",
          "c_name" : "玉门",
          "c_desc" : "一个白玉做的大门，上面各有两个碗大的雀环。\n",
          "status" : "closed"
        ]) );
        set("pre_exit_func",([
          "west":"can_pass"]));
        reset();
}
int can_pass()
{
   if ( this_player()->query("palace_war") ) return 1; 
   return 0;
}   
