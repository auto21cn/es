#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Daemon lady","魔族妇女");
    add("id",({"lady","woman","daemon"}) );
    set_short("魔族妇女");
    set_long(@LONG
这妇女在不但具有神秘的美感，同时也是贤慧勤劳的工作者。
LONG
            );
    set("unit","个");
    set("gender","female");
    set("race","daemon");
    set("alignment",-200);
    set_perm_stat("str",8);
    set("wealth/silver",150);
    set_natural_weapon(5,5,8);
    set_natural_armor(30,0);
    set("weight",400);
    wield_weapon(TWEP"mop");
}
