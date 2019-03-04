
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("山麓小径");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你很惊讶的发现这条曲折的山麓小径，此处蔓草丛生，不像是人烟常驻
之处，但是你却隐约的听见有人交谈的声音从远方传来，在山谷中轻轻的回
汤著，然而你无法很清楚的了解这声音是从何而来，也许是风声，也许是虫
鸟叫吧? 你向身旁望去，发现一个小小的石头(stone) 上似乎刻了几个字。
LONG_DESCRIPTION
        );
        set("objects", ([
		"woman" : MOB"crying" ]) );
	set( "exits", ([
                "northeast" : HAWK"room1-2",
                     ]) );
         set("c_item_desc",([
                "stone":"@@to_stone"
                        ]) );
    reset();
}//end of creat


void init()
{
        add_action("to_pray","pray");
}

string to_stone()
{
return "你看到石头上刻了几个歪歪的字，不过你依然可以辨认出来...\n\n"+
    "入山者请注意~~~~此路有去无回~~~~\n              "+
        "想回头者~~~~请诚心向上天~~~祈祷~~~吧。\n\n";
}

int to_pray()
{
        tell_object(this_player(),"你诚心的祈祷，忽然觉得一只大手把你抓了起来。\n");
        this_player()->move_player(HAWK"altar2","SNEAK");
        return 1;
}

