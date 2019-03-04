#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
        seteuid(getuid());
        set_name("messy_smell","暗夜留香");
        add("id",({"messy","smell"}));
        set_short("暗夜留香");
        set_long(
        "这是一种带有浓郁香气的药粉\n"
        "你可以用 poison <someone> 对某人下毒;用 check 检查剩馀的份量。\n"
        );
        set( "unit", "盒" );
        set_duration(10);
        set_effect(5);
        set_type("confused");
        set_times(1);
        set_difficulty(40);
        set("poison_method","%s从盒子里沾了一些$P, 吹向%s");
}

