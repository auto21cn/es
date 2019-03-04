
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("the dwarf village","矮人村");
  set_long(@Long
Long
,@CLong
这里已经是矮人村了.但是却是一片空旷,似乎没有人居住的样子.只见到
一口井(well)与及几个打水用的木桶,除此之外你还看到一个很大的洞穴在东
边,一些细微的声音从洞中传出,似乎有人住在里面的样子.
CLong
);
set("exits",([
                "west":Deathland"/dwarf/village_06",
                "east":Deathland"/dwarf/village_08",
             ]));
set("c_item_desc",([
    "well":"@@to_look_well",
    ]) );

}

string to_look_well()
{
     write("当你看著这口井,忽然你的脚滑了一下,你跌进了井里.\n\n\n\n\n"
          "\n\n\n\n\n"
          );
     say(this_player()->query("c_name")+"在井旁消失了.\n");
     this_player()->move_player(Deathland"/dwarf/well01","SNEAK","");
     return "一个很深的井,当你环顾四周时,似乎没有发现出口\n";
}
