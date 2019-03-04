#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("书房");
	set_long(@C_LONG
这房间与其说是书房，不如说是起居室。房间的大部分被一张木床占去了。
床头有个小桌子，摆了文房四宝，墨都还没乾。左边的书架上放了一些关医药方
面的书。一边的墙上挂了一幅画。
C_LONG
);
	set("light", 1);
	set("exits",([
		"west" : WANG"room3",
	]));

	set("objects", ([
		"doctor" : WANG"mob/medic.c",
	]) );

	set("c_item_desc" , ([
		"painting" : "@@look_painting",
		"画" : "@@look_painting",
	]));

        set("search_desc",([
        	"painting":"@@search_painting",
        	"画" :"@@search_painting",
	]) );

	reset();
}
string look_painting()
{
	if ( (string) this_player()->query("class") == "healer" ) {
	return 
"这画的边缘有些磨损了, 好像有人常常拿起来观赏。画上有个古典美女, \n"
"看起来笑的很开心。你再仔细一看 咦, 长的跟刑大娘还蛮像的嘛。\n" ;
	} else {
	return 
"这画的边缘有些磨损了, 好像有人常常拿起来观赏。画上有个古典美女, \n"
"看起来笑的很开心。不知道这位美女是何方佳人。\n" ;
	}
}
string search_painting()
{
	write(
	"你发现这幅画的後面果然有个通道, 於是你就走过去看看里面有什麽东西。\n");	
	this_player()->move_player(WANG"room5","SNEAK",);
	return "";
}

