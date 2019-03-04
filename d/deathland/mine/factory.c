
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The Factory of Drawf mine","炼矿厂");
    set_long(@Long
Long
,@CLong
一堆一堆的矿石堆积在此,而一些有经验的矮人矿工正在把矿石分类,然候送
上输送带.输送带的末端是一座巨大的火炉, 熊熊的火焰生生不息地燃烧著.这里
是一座炼矿厂 .你看著这些非常进步的设备不禁怀疑以矮人的文明是如何造出这
些器具的 .有一些运矿车正在把矿石卸下,另一些空的运矿车正开出这里去运矿.
每个矮人都非常辛勤的工作.而在地上有铁轨铺设著.专供运矿车通行使用.
CLong
);
set("open_cart",1);
set("exits",([
            "west":Deathland"/mine/mine_01",
             ]));

set("objects",([
    "homdlaser":Monster"/homdlaser",
   ]));
set("direction","west");
::reset();
}

int clean_up() { return 0; } 
