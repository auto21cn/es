#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"

inherit MONSTER;

void create()
{
  ::create();
  set_level(18);
  set_name("crystal leech", "天水蚂蝗");
  add( "id", ({ "leech" }) );
  set_short("天水蚂蝗");
  set_long(@LONG
一种吸血水蛭，因为通体透明，就如同天池之水一般，所以人称天水蚂蝗。每
当它吸食其他动物血液的时候，自身透明的体液和鲜血混在一起，会变成如玫
瑰石般□丽的色泽，十分好看。
LONG
    );
  set( "race", "amphibia" );
  set( "unit", "只" ); 
  set( "alignment", -800 );
  set_natural_armor( 10, 20 );
  set( "max_hp", 600 );
  set( "hit_points", 600 );
  set_skill("dodge",100);
  set_perm_stat( "int", 20 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 30 );
  set_natural_weapon(60,30,50);
  set("aim_difficulty",(["critical":90,"ganglion":50]));
  set("special_defense",(["all":40,"none":20]));
  set( "killer", 1 );
  set( "time_to_heal", 40 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "头部", "身体", "腹部", "尾部" }) );
  set_c_verbs( ({ "%s狠狠的咬住%s的皮肤，开始吸血" ,
                  "%s用腹部尖锐的牙齿划破了%s的皮肤"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>8 || !(victim= query_attacker()) ) return 0;   
  if (random(5)>2) { 
    tell_object( victim,
      "\n蚂蝗紧紧的咬住你的手臂，只见蚂蝗的颜色由透明转为粉红，鲜艳异常....\n\n"
      );
    victim->receive_damage(30);
    this_object()->receive_healing(30);  
    report(this_object(),victim);
    return 1;
  }
tell_object(victim,
  "你的大腿因为被蚂蝗咬了一口而麻痹了......\n");
  victim->block_attack(2);
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",4);
     ::die();
}