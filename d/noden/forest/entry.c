#include "forest.h"

inherit ROOM;

void create()
{
	::create();
	set_outside("noden");
	set_short("黑森林");
	set_long(@CLong
你站在黑森林的入口。如它的名字一般, 这个森林的树木异常地茂密
, 使得无论多麽强烈的阳光都完全无法穿透进来。据传说, 这是受到魔族
邪恶魔法的影响, 森林中的一草一木、小动物们都变成邪恶的黑暗生物。
    此外, 许多传言指出此地有著前往魔族古帝国的秘密通道。
CLong
);
	set("exits",([
		"north" : HERE"1n",
		"south" : "/d/noden/8,14.noden",
	]));
	set("no_monster", 1);
	set("exit_suppress", ({ "north", }) );
  	reset();

}
