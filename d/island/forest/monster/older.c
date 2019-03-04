#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Daemon older","魔族老者");
    add("id",({"older","daemon"}) );
    set_short("魔族老者");
    set_long(@LONG
这老者年纪已经一大把了，看起来仍是十分硬朗的样子；手中拿个根烟斗，一幅
若有所思的模样。
LONG
            );
    set("unit","个");
    set("gender","male");
    set("race","daemon");
    set("alignment",-250);
    set_perm_stat("str",9);
    set("wealth/silver",150);
    set_natural_weapon(6,7,12);
    set_natural_armor(35,0);
    set("weight",600);
    wield_weapon(TWEP"pipe");
}
