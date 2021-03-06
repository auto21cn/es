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
你，好像对著你说：『快来吧，快来吧，我的食物』。东和西边是一堆和人同高度
的野草；道路往南、北边延申。
LONG);
    set( "exits", ([
         "south":LAKE"village10",
        "north":LAKE"village18"
    ]) );
    set("objects",([
        "boy#1":LMONSTER"boy",
        "boy#2":LMONSTER"boy",
        "girl#1":LMONSTER"girl",
    ]) );
    ::reset();
}
