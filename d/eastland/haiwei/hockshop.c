// File: /d/eastland/haiwei/hockshop.c
// Generated by Roommaker Sat Jan 22 13:08:55 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("丰来当铺");
        set_long( @C_LONG_DESCRIPTION
你现在走进了一间布置得相当考究的厅院，门口一爿蓝色的布帘上写著四个大字
「丰来当铺」，这家当铺是海威镇大财主聂员外的产业，大朝奉钱先生是从京城来的
有名骨董专家，对稀奇古怪的东西特别有研究。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits", ([ 
                "east" : "/d/eastland/haiwei/mroad4" ]) );
        set( "objects", ([
                "keeper" : "/d/eastland/haiwei/monster/keeper_chien" ]) );
        reset();
#include <replace_room.h>
}
