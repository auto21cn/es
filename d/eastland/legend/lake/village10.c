#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("渔村道路");
        set_long( 
@LONG
你正走在渔村的道路上，迎面扑来的是一股浓浓的腥臭味；在地上，纵横交错
著血水枯乾的小河；一团团苍蝇，正汲汲於腐烂的鱼肉上，不时发出嗡嗡地鸣声。
晦暗不明的天空，乌云团簇好似一只只正在张牙舞爪的野兽，野兽正恶狠狠地瞪著
你，好像对著你说：『快来吧，快来吧，我的食物』。渔村道路往南、北边延申，
西边有一片小空地，东边有一间矮房子。
LONG);
    set("c_item_desc",([
        "矮房子":"一间破旧的老房子，屋顶没了，只留下三面斑白的墙壁，想必是没人住。\n",
        "小空地":"一块小小的空地，地上野草丛生。\n"   
    ]) );            
    set( "light",1);
    set( "exit_suppress", ({
          "west" }) );
             
    set( "exits", ([
          "north":LAKE"village17",
          "west":LAKE"village19",
         "south":LAKE"village9"
    ]) );
    ::reset();
}
