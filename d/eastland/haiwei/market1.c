// File: /d/eastland/haiwei/market1.c
// Generated by Roommaker Thu Dec 30 02:11:04 1993

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("鱼市场");
        set_long( @C_LONG_DESCRIPTION
你现在来到海威镇的鱼市场中，这里原来是从前的造船厂，但是现在渔民们都
将在海上捕到的渔获拿到这里拍卖，久而久之就成了专卖渔获的市集，地面上到处
都是从鱼篓中落下来的鱼鳞和血水，一股浓浓的鱼腥味充斥这整个市场。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/market3", 
                "north" : "/d/eastland/haiwei/road_cross", 
                "west" : "/d/eastland/haiwei/market2" ]) );
        reset();
#include <replace_room.h>
}
