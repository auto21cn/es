#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Guan Sheng","关胜");
    add("id",({"guan","sheng"}) );
    set_short("关胜");
	set_long(@C_LONG
外号大刀关胜，幼读兵书，深通武艺，使一口青龙偃月刀，有万夫不当
之勇。本充蒲东巡简．生的卧蚕眉，丹凤眼，面如重枣，现为梁山泊马
军五虎将中第一大将。
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",25);
    set_perm_stat( "int",17);
    set_perm_stat( "karma",27);
    set_skill("longblade",100);
    set_skill("parry",100);	
    set ("max_hp",1000);
    set ("hit_points",1000);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
    set ("weight", 40);
    set ("tactic_func","hack");
    equip_armor(TARMOR"green_hood");
    wield_weapon(TWEAPON"dragonblade");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"green_chainmail");
    equip_armor(TARMOR"golden_boots");
    equip_armor(TARMOR"golden_cloak");
}
int hack()
{
  object victim;
  string name,c_name;
  if (!(victim=query_attacker())) return 0;
  name =victim->query("name");
  c_name =victim->query("c_name");
  if (random(10)<2) { 
  tell_room(environment(this_object()),
  "\n关胜用台语喝道: 天罡\破....破....破....\n"
  "关胜的青龙偃月刀自半空划出一道刀光，造成敌人不可思议的伤害\n\n"
);
  victim->receive_special_damage("none",50);
return 1;
}
return 0;
}

