#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Centaur Woman","半人马农妇");
    add("id",({"centaur","woman"}) );
    set_short("半人马农妇");
    set_long(@C_LONG
这是一个魔族的『农奴』，他们祖先被迫跟随魔族的一支来到这个荒岛上垦荒。近来
天皇希望他们能增加生产力，以增强国力，抵抗蜥蜴人及人类的侵略，已经改革了很
多政策，因此虽说是奴，生活倒也过得还不错。她现在下工了，所以在公社中休息。
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-300);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set("wealth/silver",50);
    set_natural_weapon(10,8,15);
    set_natural_armor(25,0);
}

