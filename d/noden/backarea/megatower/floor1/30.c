#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The Entrance of Mega Tower","摩天塔的入口");
  set_long(@Long
Long
,@CLong
你已经进入摩天塔的内部第一层了, 这塔似乎是年久失修, 到处可见破碎的瓦片
与石块, 这地方是高塔的入口, 有一个告示牌(plaque)横躺与地上, 上面的字迹有些
模糊, 但是对你来讲了解它的意义却没什麽困难.
    这座塔是什麽人建造的, 建造它的目的又是为了什麽呢? 种种的秘密待你去探查.
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/20",
               "east" :Megatower"/floor1/40",
               "south":Megatower"/outside",
               "north":Megatower"/floor1/31",
             ]));

  set("item_func",([
      "plaque":"look_plaque",
      ]) );
::reset();
}

int look_plaque()
{
    write(
          "**********************************\n"
          "*给来到这里的朋友们,             *\n"
          "*  有著数以万计的宝藏送给你.     *\n"
          "*    ------海盗凯斯特(Keist)-----*\n"
          "**********************************\n"
          );
    return 1;
}
