#include <mudlib.h>
#include <ansi.h>

inherit MONSTER;

void create ()
{
 ::create();
 set_level(19);
 set_name("jin ke","荆轲");
 add("id","ke");
 set_short("大刺客 荆轲");
 set_long(@C_LONG
 赫赫有名的荆轲，曾经刺杀过秦王，他武功概世，现在他被杀手帮帮言任命
 在这里负责训练杀手的工作。只见他星目紧闭，剑眉深锁，公乎有什么事情
 需要人帮忙.\n
 @C_LONG
 );
 set("gender","male");
 set("race","drow");
 set("unit","名");
 set_perm_stat("str",30);
 set_perm_stat("int",30);
 set_perm_stat("kar",30);
 set_perm_stat("dex",30);
 set_perm_stat("pie",30);
 set_perm_stat("con",30);
 set("max_hp",3000);
 set("hit_points",3000);
 set_natural_armor(60,35);
 set_natural_weapon(72,29,55);
 set("chat_chance",10);
 set("att_chat_output",({
 "荆轲狞笑道：敢来野我?!找死!!\n"
  }));
 wield_weapon("/d/island/hole/weapon/axe1.c");
 set("inquiry",([
  "help": "@@ask_help",
  "task": "@@ask_task"]);
}

void ask_help(object asker)
{
 write(@D_LONG
 我有人任务很难完成,想多找些帮手,如果你是杀手,你可以向我问一下(task)
 如果任务完成了,我会报答你的\n
 @D_LONG
}

void ask_task(object asker)
{
write(@C_LONG
 今次的任务是杀rashudi...
 @C_LONG
}


