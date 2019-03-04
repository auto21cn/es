
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("72 critical-skill room","少林七十二绝技练功\房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
此处是一个四通八达的房间，可通往各个绝技习练房。原本少林七十二绝技是存放於
藏经阁，结果使得藏经阁成了武林枭雄觊觎之处。为恐此经书落入坏人手中。所以少林寺
把七十二绝技的武功\密笈分散，分别摆\入各个绝技习练房中，而每个房间由一位少林高僧
看守。此僧必精研此一绝技。他一方面可守护经书，另一方面负责传授此一绝学予後进。
四周墙上留有一些学习绝技的注意事项(note)，请你先看清楚。
往东、西、南、北、上 各通往一间七十二绝技习练房。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "note":@BOOK

少林素以七十二绝技享誉江湖，学习少林七十二绝技自必是每一位少林武僧的心愿。
但基础功\夫没练到家的人，强学七十二绝技只会走火入魔，所以本寺对於每一项绝技
之习练都有很多限制及要求。
七十二绝技乃少林镇山之宝，而每人天资聪慧各不相同，故为安全起见，目前限制每
位武僧只能修习一项绝技。但你如果能证明自己天资过人、武功\盖\世，或者你对少林
寺有特殊贡献者，将可多学一些绝技。
要学一项绝技前必需先熟练相关的基础武学，如果要改练其它72绝技，旧有功力将不
废除，只是无法使用。  

                                                                 方丈
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"down" : SAULIN"inner_room",
		"west" : SAULIN"bolo_room",
		"south" : SAULIN"body_room",
		"north" : SAULIN"flower_room",
		"east" : SAULIN"dragon_room", 
		"up" : SAULIN"power_room" ]) );
	reset();
}

