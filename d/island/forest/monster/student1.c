#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Daemon girl student","魔族女学生");
    add("id",({"daemon","girl","student"}) );
    set_short("魔族女学生");
    set_long(@LONG
一个魔族的小女孩，似乎无视於你的存在，专心的听著先生讲课。
LONG
            );
    set("unit","个");
    set("alignment",-50);
    set("gender","female");
    set("race","daemon");
    set("weight",150);
    set_perm_stat("dex",6);
    set_natural_weapon(3,3,5);
    set_natural_armor(20,0);
    set("wealth/silver",20);
}    
