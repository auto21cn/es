#include <mudlib.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(16);
  set_name("woman", "妈妈桑");
  add( "id", ({ "woman" }) );
  set_short("妈妈桑");
  set_long(@C_LONG
一位上了年纪的妈妈桑。妈妈桑现在正打著赤脚，辛勤地在井边边洗衣服边和旁边
的妇人聊天。对於初到此地的你而言，或许可以向她们打听个什麽消息也说不定。  
C_LONG  
    );
  set( "race", "human" );
  set( "unit", "个" );
  set( "gender", "female");
  set_natural_weapon(30,18,33);
  set_natural_armor( 70, 18 );
  set( "max_hp", 400 );
  set( "hit_points", 400 );
  set_perm_stat( "int", 17 );
  set_perm_stat( "str", 20 );
  set_perm_stat( "dex", 22 );
  set_perm_stat( "pie", 18 );
  set( "inquiry", ([
     "村长":"@@ask_captain",
  ]) );
  set( "tactic_func", "my_attack" );
}
void ask_captain(object asker)
{
write(@C_LONG
妈妈桑道：喔，村长的家就在前面不远处的矮房子。唉，可怜的村长．．
C_LONG
     );
}
int my_attack()
{
  object victim;
  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object(victim,"妈妈桑拿起她的洗衣刷往你面门一丢\n");
  tell_room(environment(this_object()),sprintf(
       "妈妈桑拿起她的洗衣刷往%s面门一丢\n",victim->query("c_name")),victim);
  victim->receive_damage(10);
  return 0;
}
