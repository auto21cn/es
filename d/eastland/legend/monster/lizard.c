#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(13);
  set_name("huge lizard", "食人蜥蜴");
  add( "id", ({ "lizard" }) );
  set_short("食人蜥蜴");
  set_long(
    "一只巨大的蜥蜴，浑身上下都由一层红色的液体覆盖著。\n"
    );
  set( "race", "amphibia" );
  set("killer",1);
  set( "unit", "只" );
  set( "exp_reward", 1500 );
  set( "alignment", -800 );
  set_natural_weapon(40,20,20);
  set_natural_armor( 45, 10 );
  set( "max_hp", 300 );
  set( "hit_points", 300 );
  set( "aim_difficulty",(["ganglion":70]));
  set_perm_stat( "int", 1 );
  set_perm_stat( "str",40 );
  set_perm_stat( "dex", 15 );
  set_perm_stat( "str", 25 );
  set( "aggressive", 1 );
  set( "time_to_heal", 10 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "头部", "身体", "前脚", "後脚" }) );
  set_c_verbs( ({ "%s伸出□绿色的舌头，卷向%s" ,
                  "%s用它的尾巴转身扫向%s"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object( environment(this_object()),@LONG
你狠狠的击中了食人蜥蜴的尾巴， 但是一股腥臭的暗红色液体却由
蜥蜴的伤口喷了出来，溅到了你的身上......
LONG
    );
  (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 10 );
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",2);
     ::die();
}