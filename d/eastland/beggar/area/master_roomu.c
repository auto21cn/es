#include "/d/eastland/beggar/dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "master_room", "『赏善罚恶厅』" );
	set_long(@C_LONG
这里是『赏善罚恶厅』的二楼, 这里算得上布置的满精致的;你右边的墙壁上
有一幅泼墨的山水画, 画对面的墙上有一张连带虎头的老虎皮;房间的中央铺著一
长条的红色地毯,地毯的两旁有著八张用绘木做成的椅子; 地毯的尽头有一张太师
椅,椅上铺著的是一张大黑熊皮;太师椅後面的墙上供奉著『武圣』关公的肖像,关
公两旁各是关平和手持青龙偃月刀的周仓。旁边有一个楼梯可以通往下面。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "down":DBEGGAR"master_room.c"
	]) );
        set( "objects", ([
                      "master of beggar":DMONSTER"master.c",
                             "master Wu":DMONSTER"wu_master.c",         
                               "servant1":DMONSTER"servant.c",
                               "servant2":DMONSTER"servant.c" 
        ]) );
        set_reset(this_object(),21600);
}
void reset()
{
   set_reset(this_object(),21600);
   ::reset();
}
void init()
{
    if ( this_player()->query("class") != "thief" )
        return ;
    if ( !this_player()->query_temp("hidding"))
        return ;
    if ( random(20) > 18 )
        return ;
    this_player()->delete_temp("hidding");
    call_out("recover",1,this_player());
}
void recover(object obj)
{
    obj->block_attack(6);
    obj->set_temp("msg_stop_attack",
           "( 你潜行失败，被敌人突袭，一阵手忙脚乱！ )\n" );
}