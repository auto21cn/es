#include "/d/eastland/beggar/dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "hospital1", "药铺二楼" );
	set_long(@C_LONG
这里是药铺的二楼, 是『一代神医 小雪子』用来医治病患的地方。这个房间
里最醒目的就是放在房间中央, 供小雪子练习针灸的铜人模型,上面标示著一大堆
的经脉和术语。房间的右边是一个小小的书桌, 虽然上面凌乱不堪,但放著的都是
很有用的医书。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "down":DBEGGAR"hospital.c"
	]) );
     
        set( "objects", ([
                         "uki" : DMONSTER"uki.c",
                         "ahtu": DMONSTER"ahtu.c" 
                         ]) );
     reset();
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
