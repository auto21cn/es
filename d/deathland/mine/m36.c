
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" Drawf mine ","矮人矿坑");
  set_long(@Long
Long
,@CLong
这里是矿坑的深处.你能看到的是一个周围的岩壁充满著被挖掘的痕迹以及
用木头架设著以免塌陷的岩洞.在地上有铁轨铺设著.专供运矿车通行使用.然而
这里是铁轨的尽头,前面的路似乎被一堆塌陷的石块与木头挡住了去路.
CLong
);
set("direction","block");
set("objects",([
    "rat":Monster"/rat",
]) );
set("exits",([
             "northeast":Mine"/m23",
             ]));
#include <replace_room.h>
}
