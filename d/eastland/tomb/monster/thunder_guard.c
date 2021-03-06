#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "thunder guard", "雷之护卫" );
        add ("id", ({ "thunder", "guard" }) );
        set_short( "雷之护卫");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"一位雷之护卫，是大国师用道家正统心法所招唤出来的，他负有守卫此地的神圣
使命\。\n"
        );
        set_perm_stat("int", 25);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 23);
        set_perm_stat("con",30);
        set_perm_stat("kar",25);
        set_natural_weapon( 55, 25, 45 );
        set_natural_armor( 70, 8 );
        set("skills",(["parry":80]) );
        set("gender", "male");
        set("race", "daemon");
        set("tactic_func","thunder_tactic");
        set("special_defense",(["electricl":40,"all":20]));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        equip_armor(ARMORS"/thunder_gloves");
        equip_armor(ARMORS"/thunder_amulet");
}

int thunder_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"雷之护卫突然高举他的护符，两三条电光自护符中发出向你射来 !!\n",
       this_object() );
  dam = 50 + random(30);
  victim->receive_special_damage("electric",dam);
  return 1;
}

