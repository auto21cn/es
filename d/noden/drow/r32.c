#include "iigima.h"

inherit ROOM;

int adv;

void create()
{

        ::create();
        set_short( "desk","祭坛");
        set_long(
@C_LONG
来到这里，你看到一个偌大的祭坛，由四方形的石砖砌成的祭坛，
四周由八个大柱子支撑著祭坛的方形顶盘，顶盘上盘著无数条巨蛇的石
像(statue)□吓！一阵刺耳的尖锐叫声，从前方的引道传来，你的勇气
鼓励你勇敢的迈开步伐向前进！
C_LONG
        );
        set( "light",1 );
        set( "exits", ([
                     "northwest": DROW"r29",
                    
                     "south": DROW"r33",
        ]) );
        set("c_item_desc",([
              "statue":
@C_LONG
吓！！好大的蛇像，栩栩如生的模样，张牙舞爪似乎要一口吞了你！
咦？蛇像的基座有个小洞(hole)，看来怪怪的....
C_LONG
,             "hole":
@C_LONG
这个小洞看来形状怪怪的，不像被腐蚀的痕迹，倒像某种卡锁，
好像可以放入(put)什麽东西....
C_LONG
     ])); 
        reset();
}

void init()
{
   add_action("do_put","put");
}

int do_put(string str)
{
        object ob,player;
        string scale;
        player = this_player();

   if( !str || str != "scale into hole" ) {
        write( "你要做啥?\n" );
        return 1;
     }
        ob = present("scale",player);
   if( !ob ) {
        write( "你身上没有蛇鳞！\n" );
        return 1;
     }
   if( adv ) {
        tell_object( player,
                    "你把蛇鳞放进祭坛上的一个小洞，卡一声！瞬时卡锁弹开，锁链松开了！\n"
                    "\n"
                    "你听到东北方传来阵阵的怪叫声，噫～好可怕。\n"
                    );
        add("exits",(["northeast":DROW"r30"]));
	new(DRO"teeder")->move(this_object());
   ob->remove();
                    adv = 0;
                return 1; 
     }
        else tell_object( player,
                    "你放入了蛇鳞，但是什麽事都没有发生。\n" );
   ob->remove();
   return 1;
}

void reset()
{
   room::reset();
   adv = 1;
   delete( "exits/northeast" );
}
