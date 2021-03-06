#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object cloak;
        ::create();
        set_level(18);
        set_name( "draconian flamen budbadbump", "龙人祭司 巴德北特.庞博" );
        add ("id", ({ "draconian", "flamen","budbadbump" }) );
        set_short( " 龙人祭司 巴德北特.庞博");
        set("unit","位");
        set("alignment",600);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
龙人祭司 巴德北特.庞博是一个博学多才的人，他对许\多神秘的事件有独特
的研究，例如巫术，针灸，内功\，以及古文明的祭典等都有其独到的见解，
实是一个值的敬重的老先生。
C_LONG
        );
        set_perm_stat("int", 26);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",20);
        set("max_hp",500);
        set("hit_points",500);
        set_natural_weapon(20, 10, 20);
        set_natural_armor(70, 30);
        set ("special_defense",(["all":40,"none":60]));
        set ("gender", "male");
        set_skill("shortblade",100);
        set_skill("dodge",100);
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
      
        cloak=new(Lditem"scroll");
        cloak->move(this_object());
        
        wield_weapon(Lditem"shortsword");
        equip_armor(Lditem"cloak");
        equip_armor(Lditem"leggings");
}

int sleet_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\n突然巴德北特.庞博喃喃的念出神秘的咒语，一阵冰雪风暴向你袭来。\n\n");
  dam=50 + random(30);
  magics->receive_special_damage("sleet",dam);
  return 1;
}
