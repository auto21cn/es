// File: /d/eastland/haiwei/shop.c
// Generated by Roommaker Fri Jan 21 02:37:34 1994

#include <mudlib.h>

inherit SHOP;

void create()
{
        ::create();
        set_short("聂记商行");
        set_long( @C_LONG_DESCRIPTION
你现在来到一家装饰得美仑美奂的商店，漆著乌亮光泽红漆的柜台和雕工精细
的檀木桌椅，大厅中央铺著一张白熊皮，厅上挂著一块大匾「门庭若市」，在大厅
西边一座屏风隔出一个内厅，东边是往大街的出口。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits", ([ 
                "east" : "/d/eastland/haiwei/mroad3" ]) );
        set( "objects", ([
                "trashcan" : "/obj/trashcan" ]) );
        reset();
}
