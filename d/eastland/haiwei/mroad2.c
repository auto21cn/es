// File: /d/eastland/haiwei/mroad2.c
// Generated by Roommaker Tue Jan 25 02:51:16 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("海威镇大街");
        set_long( @C_LONG_DESCRIPTION
你现在正走在海威镇的大街上，北边是一个小茶棚，茶棚外悬挂著一个素色
灯笼，上面写著「好茶亭」。往东是一条宽敞的大街，西边是条青石大道，海威
镇的居民们把这条大道称做「官道」，因为往来南北的官差常常日夜不停地纵马
驰骋在这条大道上。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/tea_shop", 
                "west" : "/d/eastland/haiwei/mroad3", 
                "east" : "/d/eastland/haiwei/mroad1" ]) );
        set( "objects", ([ 
                "soothsayer" : "/d/eastland/haiwei/monster/soothsayer" ]) );
        reset();
#include <replace_room.h>
}
