
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The squire of the dwarf village","矮人村落的广场");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村庄的大广场上,这里有著非常和平安详的气氛,矮人们经常在此地
游玩及嬉戏.东边有一个很大的水塘(pool),是矮人饮用水的来源 ,在水塘的中央有一个
飘浮的房子(house),你不能想像为何它能浮在空中而不掉下来 .在这里似乎有个小小的
门通往地下,但是你无法确定是否有著危险的事物在底下.
CLong
    );
    set("c_item_desc",([
        "pool":"一个大水塘,由於矮人的饮用水取於此地,所以此水塘禁止游泳.\n",
        "house":"一间飘浮的房子,它有著奇怪的力量,当你注视著它的时候,你发现有一\n"
                "奇异的光线从里面射了出来.\n"
                ]) ); 
    set("exits",([
                "east":Deathland"/village/v34",
                "south":Deathland"/village/v23",
                "down":Deathland"/village/d01",
             ]));
    create_door("down","up",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"一个小小的木门",
               "c_name":"小木门",
               "name":"small wooden door",
               "desc":"a small wooden door",
               ]) );
    ::reset();
}
