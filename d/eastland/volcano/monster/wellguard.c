#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(15);
	set_name( "well guard", "看井守卫" );
	set_short( "看井守卫" );
        add("id",({"guard"}));
	set_long( 
             @LONG
一位看井守卫，他是族长派来看守这口井的，不过他觉的这个工作挺无聊的，但是
不要以为他好欺负，毕竟没有两把刷子是不会被酋长重用的。
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set( "max_hp", 500);
        set( "hit_points", 500);
        set_natural_armor(80,45);
        set_natural_weapon(15,5,10);
        wield_weapon(OWEAPON"spear1");
        equip_armor(OARMOR"cloak3");
        set ("chat_chance", 15);
        set ("chat_output", ({
             "守卫说：好无聊喔!\n",
             "守卫说：请不要乱丢(toss)东西到井里好吗 ?\n",
             "守卫说：你愿意陪我聊天解闷吗 ?\n",
             "守卫说：生命诚可贵，请不要跳井自杀。\n",
             }) );
        set ( "inquiry", ([
              "well" : "@@ask_well",
              "water": "@@ask_water",
              ]) );
}

void ask_well(object who)
{
   write("\n守卫说：这口井是我们族人的生命，我誓死也要守住它。\n");
   return;
}

void ask_water(object who)
{
  write("\n守卫说：你口渴了吗 ? 我舀一口水给你吧 !\n");
  write("\n你说：谢谢啦 !\n");
  write("\n守卫说：不客气 !\n");
  return;
}
