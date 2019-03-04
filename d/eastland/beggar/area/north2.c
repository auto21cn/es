#include "/d/eastland/beggar/dony.h"
//inherit "/d/eastland/beggar/area/ch_stun.c";
inherit ROOM;
void create()
{
	object mob;
	::create();
        set_short( "north2", "村路" );
     	set_long(@C_LONG
你现在正走在一条颇为宽大的村路上,约可容纳两匹马并行。村路向南、北方
向延伸。这条村路整理得蛮乾净的,路旁的植物修缉的很整齐,花儿欣欣向荣,比起
广场那片光秃秃的景像自是不可而语。毕竟这条是连接几个较大铺子,可说是村内
最繁华的道路。虽是如此, 却看不出任何人工刻意留下来的痕迹,这一定是出自於
某位名匠之手。西边是一家打铁铺。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "west":DBEGGAR"smith.c",
                      "south":DBEGGAR"north1.c",
	              "north":DBEGGAR"north3.c"
	]) );
        mob=new(DMONSTER"soothsayer");
        mob->move(this_object());
     reset();
}
void init()
{
    add_action("do_backstab","backstab");
}
int clean_up()
{
    return 0;
}        
void do_backstab(string str)
{
    object temp;
   if (str){
      tell_object(this_player(),
       "想 bs ? 别傻了。\n");
      this_player()->set_temp("block_command",1);
      call_out("recover1",5,this_player());
      return ;
   }
      return ;
}
void recover1(object obj)
{
     obj->delete_temp("block_command");
     tell_object(obj,
         "除了 bs 之外,难道没有别的方法?\n");
}
