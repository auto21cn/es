#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "市场" );
        set_long(
@LONG
这是一座市场，叫卖的声音此起彼落，吵闹的人潮川流不息，形成
一片热闹非凡的景象。同时这里也是古梅镇妇女的重要消息来源，只要
你在路旁待上一时三刻，保证可以听到各种奇奇怪怪的大小杂事，而且
有耳朵长茧的危险，南方是一条青石板道。在你的北方一眼望去都是杂
乱肮脏的贫民窟，杂草野花在颓圮的废墟中孳生，那应该是本镇的旧镇
址。
LONG
        );
        
        set( "exits", ([ 
                "south" : Goomay"row21",
		"north" : Goomay"ruin1",
        ]) );
        
        set( "objects", ([
                "woman1" : Mob"woman",
                "woman2" : Mob"woman",
                "merchant" : Mob"merchant",
        ]) );
        set("exit_suppress", ({ "north" }) );
set("pre_exit_func",([
    "north":"to_north",
    ]) );
        reset();
}
int to_north()
{
    write("你穿过拥挤的人群，进入了荒烟蔓草的废墟.\n");
    return 0;
}

