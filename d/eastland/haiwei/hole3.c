// File: /d/eastland/haiwei/inn1.c
// Generated by Roommaker Sat Jan 22 03:02:22 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("地洞");
        set_long( @C_LONG_DESCRIPTION
这里是一个不见天日的地洞，地面有一些积水，因此有很重的湿气让你觉的混身不舒服
，这里只有东方有一个出口，在东方有一火推正熊熊的燃烧著。
C_LONG_DESCRIPTION
        );
    set("light",1);
    set("objecs",([
        "boy":"/d/eastland/haiwei/monster/boy"]));
        set( "exits", ([ 
                "up" : "/d/eastland/haiwei/cornfield2", 
                "west" : "/d/eastland/haiwei/hole2" ]) );
        reset();
}
