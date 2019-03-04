#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("The vault of kitchen","库房");
  set_long(@Long
Long
,@CLong
这里是粮食库，堆放了如山的米袋和各种食物，平时这儿应该是很乾净的，但是
你却觉得你脚下全是米粒，踩起来怪不舒服的，而且米袋(bag) 也放得歪七扭八地，
像是被人翻箱倒柜过一般。
CLong
);
set("light",1);
set("c_item_desc",([ "bag":"@@to_bag" ]) );
set("exits",([ "west":MUMAR"kitchen" ]));
set("objects",([ "cookie":MOB"cook_master"]) );
reset();
}
 
string to_bag()
{
    return "你看著看著，不知不觉数了起来......一共是三十二包。\n";
}
