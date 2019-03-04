#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Centaur Worker","半人马工人");
    add("id",({"centaur","worker"}) );
    set_short("半人马工人");
    set_long(@C_LONG
这是一个魔族的『工奴』，他们祖先被迫跟随魔族的一支来到这个荒岛上垦荒。近来
天皇希望他们能增加生产力，以增强国力，抵抗蜥蜴人及人类的侵略，已经改革了许
多政策，因此虽说是奴，生活倒也过得还不错。
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",200);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",10);
    set_perm_stat("dex",10);
    set_natural_weapon(15,13,22);
    set_natural_armor(30,5);
    set("wealth/silver",200);
}
