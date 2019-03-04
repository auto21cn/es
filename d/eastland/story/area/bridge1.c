#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("浮桥");
	set_long( @LONG
你站在浮桥上往四周观望，底下是一溪谷，急湍澎湃，「刷刷」有声，不知高
度若何，否则大可一游而尽兴。北方的远处是层峦叠峰，一幕幕的绿布不住地往天
际延伸；抬头一望，白云只不过离头顶数尺高度，好似一条素色的被子，像将要压
下来。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "hole"}) );
	set( "exits", ([ 
               "east" : SAREA"mountain4",
       	      "south" : SAREA"mountain2",
        ]) );
	set("exit",({"east"}));
	reset();
}
