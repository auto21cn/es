#include "../../story.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
	set_short("铁扇公主的偏殿");
	set_long( @LONG
这里是铁扇公主的住所。地面整玉建成，玉质特佳，光明若镜；四周彩壁画梁
，内中翡翠家俱，云案玉几，殿偏一个椭圆形宝塌，上面凤凰锦被，绣巾罗帕，扑
鼻香气，旁边一面古色古香特制大铜镜；全殿富贵十足，不可而语。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"road1"
        ]) );
        set( "objects", ([
           "servant1" : SWMOB"f_servant1",
           "servant2" : SWMOB"f_servant1",
           "servant3" : SWMOB"f_servant1",
           "princess" : SWMOB"princess1",
        ]) );
	create_door( "south","north" ,([
	  "keyword" : ({ "golden door", "door" }),
	     "name" : "golden door",
	   "c_name" : "金门",
	   "c_desc" : "一个金澄澄的大门，上面各有两个雀环。\n",
	   "status" : "closed"
	]) );
	reset();
}
