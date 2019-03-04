#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(15);
    set_name("Shi Tsen","时迁");
    add("id",({"thief","shi","tsen"}) );
    set_short("时迁");
	set_long(@C_LONG
高唐州人士，外号鼓上蚤，手脚灵便，盗窃成性，行事机警，为梁山泊军中报机密
步军头领．看到他你不禁抓紧你的钱包．
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",20);
    set_perm_stat( "int",19);
    set_perm_stat( "karma",26);
    set_skill("dagger",60);
    set_skill("dodge",90);	
    set ("max_hp",360);
    set ("hit_points",360);
    set ("wealth", ([ "gold":10]) );
    set_natural_weapon(8,8,9);
	set_natural_armor(28,12);
	set ("aim_difficulty",([ "gangolion":33,"vascular":38]) );
	set("special_defense", (["all":17,"none":20]) );
    set ("weight", 40);
    set ("tactic_func","steal");
    equip_armor(TARMOR"thief_amulet");
    equip_armor(TARMOR"simple_boots");
    wield_weapon(TWEAPON"thief_dagger");
    equip_armor(TARMOR"small_cloth");
}
int steal()
{
  object victim;
  string name,c_name;
  if (!(victim=query_attacker())) return 0;
  name =victim->query("name");
  c_name =victim->query("c_name");
  if (random(10)<2) { 
  tell_room(environment(this_object()),
  "\n时迁一甩手，射出一把金钱镖攻击敌人....\n\n"
);
  victim->receive_special_damage("none",10);
  victim->add("wealth/gold",1);
return 1;
}
  if (random(10)<2 && victim->query("wealth/gold")>10) {
  tell_room(environment(this_object()),
  "\n时迁偷走了"+c_name+"一些钱，顺便赏他一巴掌....\n\n"
);
  victim->receive_special_damage("evil",8);
  victim->set("wealth/gold",(int)(victim->query("wealth/gold"))-10);
  return 1;
}
return 0;
}

