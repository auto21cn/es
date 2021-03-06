#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(12);
    set_name("dwarf guard","矮人守卫");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a dwarf guard",
           "矮人守卫");
	set_long(@LONG
这个矮人守卫正保卫在矮人村庄的入口,但是他似乎渴望著能离开这里到
酒吧(Pub)去.
LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
	set_skill("shortblade",78);
	set_skill("parry",55);
    set ("max_hp",390);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "gold":13]) );
    set_natural_weapon(27,15,25);
	set_natural_armor(43,19);
    set ("weight", 350);
    set ("inquiry",([
         "pub":"@@ask_pub",
         "wine":"@@ask_wine",
         "maze":"@@ask_maze",
        ]) );
    
    set("chat_chance",10);
    set("chat_output",({
        "守卫很想要睡觉但是在岗位上因此他觉得很无奈.\n",
        "守卫说:假使你迷失在迷宫(maze)中,往西三四步你就可以离开了.\n"
       }) );
    equip_armor(Armour"/ringmail01");
    wield_weapon(Weapon"/shortsword02");
    equip_armor(Armour"/armband01");
     
}

void ask_pub(object who)
{
  tell_object(who,@MSG1
守卫说:当我在站岗的时候,不要跟我提起酒吧,那会让我想起美妙的啤酒(wine),
守卫吞了一口口水.
MSG1
   );

}

void ask_wine(object who)
{
   tell_object(who,@MSG2
啤酒,可恶,当我在站岗的时候,不要跟我提起酒,我会忍不住想要偷喝,可是这是违
反纪律的.守卫瞪著你说

不过一些果汁或许可以让我解解馋.守卫又吞了一口口水.
MSG2
   );
}

void ask_maze(object who)
{
   tell_object(who,@MSG3
守卫说:这迷宫已经帮助我们许\多次,在多次的矮人巨人战争中,巨人总是无法
突破这最後一道防线.这个迷宫的魔法障壁并不是一般人能解开的.嗨!嗨!
MSG3
   );
}

int accept_item(object ob1,object ob2)
{
    if ( !( ob2->id("juice") ) )
      return 0;
    else
      {
      tell_object(environment(),@MSG4
守卫说:谢谢.
守卫很快地把果汁当成酒地喝了起来然後跟你闲聊了起来
守卫著这个地方其实蛮恐怖的, 洞里中不知道会有甚麽奇奇怪怪的东西
跑出来, 而且地底常常有一些莫名奇妙的声音传出, 常让我觉得很可怕
所以一但有空的时候, 我就会到酒吧去喝酒聊天, 你知道酒吧罢, 那儿
的酒保是个很有趣的家伙, 他知道许\许\多多的传闻轶事(rumors).
MSG4
       );
      ob1->set_explore("deathland#36");
      ob2->remove();
      return 1;
      }
}
