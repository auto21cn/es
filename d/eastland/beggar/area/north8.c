#include "../dony.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "north8", "村路" );
	set_long(@C_LONG
你现在正走在一条颇为宽大的村路上,约可容纳两匹马并行。村路向东、西方
向延伸。这条村路整理得蛮乾净的,路旁的植物修缉的很整齐,花儿欣欣向荣,比起
广场那片光秃秃的景像自是不可而语。毕竟这条是连接几个较大铺子,可说是村内
最繁华的道路。虽是如此, 却看不出任何人工刻意留下来的痕迹,这一定是出自於
某位名匠之手。由北边远远地望去,一排排矮矮的房子显然是村内人们居住的地方
。西边通往『赏善罚恶厅』。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"north5.c",
                      "west":DBEGGAR"north10.c" 
	]) );
        set( "pre_exit_func", 
                      ([ 
                      "east": "can_pass",
                      "west": "can_pass"
        ]) );
        set( "objects", ([
                      "chau":DMONSTER"chau.c",
                      "burro":DMONSTER"donkey.c"
        ]) );                                    
     reset();
}

int can_pass()
{ 
   
   if( this_player()->query_temp("mounting") && !wizardp(this_player() ) 
       &&  present("chau") ){  
      tell_object(this_player(),
        "赵钱孙把你拦了下来恕道:怎麽你的马跟我的驴子那麽像,是不是我的?\n" );
            return 1;
     } return 0;
}
