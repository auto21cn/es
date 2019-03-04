#include <mumar.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("库房");
  set_long( @CLong
这里是牧马关的武器仓库，墙上整齐地排列著各式各样的武器装备，从刀剑斧矛
到弓弩火炮，样样俱全，多得让你眼花撩乱。听说这儿还收藏著一些御赐的神兵利器
与来往行商所奉献的珍奇宝物。
CLong
);
set("light",1);
set("exits",([
               "east":MUMAR"vault01",
             ]));
set("objects",([
               "advisor":MOB"advisor",
               ]) );
 
create_door( "east","west",
           (["keyword" : ({"copper","door"}),
             "name"    : "copper door",
             "c_name"  : "铜门",
             "c_desc"  : "一扇铜门。\n",
             "status"  : "closed"
           ]) );
reset();
}
