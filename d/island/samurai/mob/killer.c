#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Killer Genan", "杀手 幻庵" );
	add( "id", ({ "killer","genan" }) );
	set_short( "Killer Genan", "杀手 幻庵" );
	set_long(@AAA
幻庵是一个外表可起来相当邪恶的男子，浑身散发出一股强烈的杀气，他
是武士团所属的特殊杀手，据说他曾经刺杀过遥照天皇，虽然没有成功但
仍能全身而退，可见他的厉害了！！
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );    
        set( "max_hp",700 );
        set( "hit_points",700 );
 	set_natural_armor( 90,40 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":35,"none":35 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":30,"ganglion":50,
                                 "vascular":30 ]));
        set( "stun_difficulty/ma",10);  
	set( "alignment", -2500 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "dodge",100);
        set_skill("tactic",100);
        set("tactic","berserk");
        set( "wealth" , ([ "gold": 50 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"lock");    
}
int att_gonfus()
{
     object victim;
     int dam1,dam2,n;
     
     if( !(victim = query_attacker()) || (random(20)>4) ) return 0;
     else {
     switch (n=random(2))
{ case 0:
    {
     tell_room(environment(this_object()), 
     "\n幻庵突然张口对"+victim->query("c_name")+"喷了一口毒气\n\n"
     );
      dam1 = 15 + random(25);
      victim->receive_special_damage("poison", dam1 );
      report(this_object(),victim);
      return 1;
      }
  case 1:
     { 
       tell_room(environment(this_object()),
       "\n幻庵伸手抓住"+victim->query("c_name")+"并张口开始乱咬\n\n"
       );
       dam2 = 15 + random(15);
       victim->receive_special_damage("poison",dam2);
       report(this_object(),victim);
       return 1;
      }
}
}
}
