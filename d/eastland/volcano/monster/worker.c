#include "../oldcat.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "worker", "扫地工" );
        set_short( "扫地工");
        set("unit","位");
        set_long(@LONG
扫地工的职责就是把神殿打扫乾静，让各位大德能好好的在神殿中修行，
不要小看了扫地工的工作，能把地扫得一尘不染是非常不容易的事，不信的话
你自己去试试看。
LONG
        );
        set("alignment",1000);
        set("wealth/silver",50);
        set("gender","male");
        set("race","dwarf");
        set("max_hp", 600);
        set("hit_points", 600);
        set("special_defense", ([ "all" : 45, "none" : 40 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50 ]) );
        set_perm_stat("str", 24);
        set_perm_stat("dex", 28);
        set_perm_stat("pie", 18);
        set_perm_stat("kar", 23);
        set_natural_weapon( 15, 7, 18 );
        set_natural_armor( 58, 30 );
        set_skill("dodge",100);
        set_skill("blunt",100);
        set("chat_chance",5);
        set ("chat_output",({
           "扫地工说道：扫地是一种艺术，唯有真正的高手才能扫得清洁溜溜。\n"
        }));
        set("moving",1);
        set("speed",25);
        set("patrol",({"south","south","north","north"}));
        set("tactic_func","special_attack");
        wield_weapon( OWEAPON"broom" );
        equip_armor( OARMOR"glove2" );
}

int special_attack()
{
  object *victim;
  int i;

  if (!(victim=query_attackers())) return 0;

  if (random(10)<2) return 0;

  i=sizeof(victim);
  
  if (random(10)<7) {
    tell_room(environment(this_object()),
     "\n扫地工使出扫地剑法第一式，双手握住扫把一端，急速挥动，幻成一圈黄光，向所有的敌人削去。\n\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+10);  
    return 1;
  }

  if (random(10)<7) {
    tell_room(environment(this_object()),
      "\n扫地工使出扫地剑法第二式，左手捏一剑诀，右手持扫把一端，一剑刺出，如石破天惊、风雨大至之势，剑气纵横全场。\n\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+15);
    return 1;
  }

  tell_room(environment(this_object()),
   "\n扫地工使出扫地剑法第三式，右手持扫把缓缓挥出，突然身形一变，手中扫把如灵蛇般的刺向每个敌人的咽喉。\n\n"
  ,this_object());
  while(i--)
    victim[i]->receive_damage(random(10)+20);
  return 1; 
}
