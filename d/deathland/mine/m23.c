
#include "../echobomber.h"

inherit ROOM;
inherit Deathland+"/mine/daemon/lever";

void create()
{
  ::create();
  set_short(" Drawf mine ","矮人矿坑");
  set_long(@Long
Long
,@CLong
这里是矿坑的深处.你能看到的是一个周围的岩壁充满著被挖掘的痕迹以及
用木头架设著以免塌陷的岩洞.在地上有铁轨铺设著.专供运矿车通行使用.你能
看到\许\多运矿车来来往往.在铁轨的旁边有一个推杆(lever),似乎常被人使用著.
CLong
);

set("direction","south");
set("exits",([
             "northeast":Mine"/m12",
             "south":Mine"/m35",
             "southwest":Mine"/m36",
             ]));
set("c_item_desc",([
    "lever":"一个推杆,似乎是用来控制铁轨的方向,你可以试著拉动(pull)它.\n",
    "rail":"@@rail_c_long",
    ]) );

reset();
}

void init()
{
     add_action("to_pull","pull");
}

int to_pull(string str)
{
    return pull_lever(this_object(),str);
}

string rail_c_long()
{
     return "目前铁轨通向"+to_chinese( query("direction") )+"方\n";  

}

reset()
{
  string dir;
  dir=query("direction");
  ::reset();
  set("direction",dir); 
}
