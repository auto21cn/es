
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Drawf city","矮人墓场");
  set_long(@Long
这里是矮人国度的墓场,墓场里埋藏著一些英勇战死的士兵的骨骸.每一座墓碑
的底下都有一个英勇的灵魂安息著.
Long
);
set("exits",([
            "north":Deathland"/city/g1",
            "south":Deathland"/city/g3",           
             ]));
}
