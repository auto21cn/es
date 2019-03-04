
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("the college of studing trolls' attack mode","巨人攻击模式研究室");
  set_long(@Long
Long
,@CLong
这里充满了一些奇奇怪怪的模型(model),和一大堆的记录(notes),上面记载著巨人的
种种攻击模式及弱点.
CLong
);

set("c_item_desc",([
    "model":"主要是巨人的模型,上面画了全身的穴道及弱点.\n",
    "notes":"一堆杂乱无章的计录,没有几个人能从其中找出的重要资料.\n",
    ]) );
set("exits",([
               "out":Deathland"/dwarf/village_04",
             ]));
set("objects",([
    "general":Monster"/general",
    ]) );
::reset();
#include <../replace_room.h>
}

