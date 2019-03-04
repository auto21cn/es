#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宫大殿");
	set_long( @LONG
殿前双金龙抢珠横踞其上，两侧朱漆画梁四童子二执宝剑另持羽扇神情庄肃待
立其内，其中一张绣丝烂银龙背金交椅前面翡玉白阶平时城主端於内，殿前武士护
卫文官武臣候立一旁，地上龙凤呈祥映著水晶天顶，端的是气派豪华不可而语！在
你东、西边各有甬道通往内殿。
LONG
	);
        set("light",1);
	set("get_bag",({}));
	set( "exits", ([ 
           "south" : SCITY"palace3",
            "west" : SCITY"road1"
        ]) );
        set("objects", ([
                   "king" : SWMOB"wiz_king1",
            "bodyguard#1" : SWMOB"wiz_bodyguard2",
            "bodyguard#2" : SWMOB"wiz_bodyguard2",
            "bodyguard#3" : SWMOB"wiz_bodyguard2",
        ]) );
	reset();
}
int clean_up()
{  return 0; }