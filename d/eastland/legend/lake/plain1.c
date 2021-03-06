#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "小径" );
    set_long(@C_LONG
你来到了一条清幽小径,小径的两旁有一排排不知名的树木,树枝挡住了阳光,
显得有些阴凉,树上一些鸟儿正啾啾地叫著。你东方有一面大湖,湖上波潭相映,一
波波的涟漪,一只只的白鹭丝或飞或停,煞是情趣。在旁有个告示牌 ( sign ) 。
C_LONG
    );
    set( "light",1);
    set( "can_use_sea_ball",1);
    set( "exits", ([
     "west":LAKE"plain0"
    ]) );
    set("c_item_desc",([
            "lake":"一面绿色的大湖。\n",
            "sign":@LONG
一张颇破旧的牌上面写著:


          ＸＸ　游客止步!!　ＸＸ
    
    
       近来发现湖中不时有妖怪出现,此地已列为管制区域!!
       因此,请不要在这里逗留,更严禁乱丢东西到湖里!切记切记!                  
   
   
   
LONG    ]) );
    set("pre_exit_func",([
        "tunnel":"can_pass"]));
    reset();
}

int can_pass( string arg )
{
    if ( !query("exits/tunnel") ) 
       return 1;
    if ( present("water beast",this_object()) ) {
       tell_object(this_player(),
         "无支祈以巨大的身躯拦在你身前不让你过去..\n");   
       return 1; 
    }
}

void reset()
{
    delete("exits/tunnel");
    delete("exit_suppress");
    delete("c_item_desc/water-tunnel");
    ::reset();
}