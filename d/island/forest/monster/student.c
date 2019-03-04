#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(3);
    set_name("Daemon student","魔族学生");
    add("id",({"daemon","student"}) );
    set_short("魔族学生");
    set_long(@LONG
一个魔族的小男孩，发现你在看他，趁先生不注意的时候把墨汁甩向你脸上！
LONG
            );
    set("unit","个");
    set("alignment",-50);
    set("gender","male");
    set("race","daemon");
    set("weight",200);
    set_perm_stat("str",5);
    set_natural_weapon(2,2,5);
    set_natural_armor(15,0);
    set("wealth/silver",10);
}    
