#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Farmer's wife","半人马农夫的妻子");
    add("id",({"centaur","farmer","wife"}) );
    set_short("半人马农夫的妻子");
    set_long(@C_LONG
这是一个魔族的『农奴』，他们祖先被迫跟随魔族的一支来到这个荒岛上垦荒。近来
天皇希望他们能增加生产力，以增强国力，抵抗蜥蜴人及人类的侵略，已经改革了很
多政策，因此虽说是奴，生活倒也过得还不错。
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-500);
    set("max_hp",150);
    set("hit_points",150);
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set_natural_weapon(13,10,20);
    set_natural_armor(25,0);
    set("wealth/silver",100);
    set("chat_chance",15);
    set("chat_output",({
    "半人马农夫的妻子一边工作一边骂道:死老公，听说城外那棵大树有求必应\n"
    "，要他一起去求个儿子也不肯.........\n"
      }) );
    set("inquiry",([
        "radish":"@@ask_radish"]) );
    wield_weapon(TWEP"hoe");
}

void ask_radish(object who)
{
  tell_object(who,"要萝卜呀，去那边找(search)啦，那边很多啦！\n");
  return ;
}