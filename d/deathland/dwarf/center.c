
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The new_trained_soldier center","新兵训练中心");
  set_long(@Long
Long
,@CLong
这里是专门将年轻的矮人训练成勇猛的战士的地方.每个矮人的战斗生涯几乎皆从此
处开始.
CLong
);

set("exits",([
               "out":Deathland"/dwarf/village_04",
             ]));
set("objects",([
    "teacher":Monster"/soldier03",
    "newsoldier#1":Monster"/soldier04",
    "newsoldier#2":Monster"/soldier04",
    "newsoldier#3":Monster"/soldier04", 
    ]) );
::reset();
#include <../replace_room.h>
}

