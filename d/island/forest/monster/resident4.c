#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Centaur Badgirl","半人马不良少女");
    add("id",({"centaur","badgirl","girl"}) );
    set_short("半人马不良少女");
    set_long(@C_LONG
这是一个魔族的『农奴』，他们祖先被迫跟随魔族的一支来到这个荒岛上垦荒。近来
天皇希望他们能增加生产力，以增强国力，抵抗蜥蜴人及人类的侵略，已经改革了很
多政策，因此虽说是奴，生活倒也过得还不错。这女孩因为年纪还小，又无所事事，
正四处晃汤。
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-100);
    set("max_hp",100);
    set("hit_points",100);
    set("killer",1);
    set("c_killer_msg","不良少女骂道：看啥？接著就一掌打了过来......\n");
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set("wealth/silver",20);
    set_natural_weapon(10,8,15);
    set_natural_armor(25,0);
}

