#include "../legend.h"

inherit LAKE+"in_lake1";

void create()
{
        ::create();
    set_short("大海");
        set_long( 
@LONG
你划著船桨来到了海面上，极目四眺，是一片风平浪静的无垠大海，远处几艘
渔船正随著波浪载浮载沈，撒网成群，辛勤地捕著渔。波面上不时穿梭著飞鱼，阳
光反射其身上，好似一颗颗亮晶晶的银宝石。
LONG
    );
    ::reset();     
}

