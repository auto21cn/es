#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "samurai Zark","武士 札克" );
	add( "id", ({ "samurai","zark" }) );
	set_short( "武士 札克" );
	set_long(@AAA
札克是一个研究空手武术的高手,但是自从他得到了魔剑(音升之剑)後,他就至
力於剑术上的研究,以他在空手武术上的速度,在加上魔剑的威力,想打赢他可
不是一件容易的事情
AAA
   );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );    
        set( "max_hp",1000 );
        set( "hit_points",1000 );
 	set_natural_armor( 85,25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":5,"none":5 ])); 
        set( "aim_difficulty",([ "critical":50,"weakest":20,"ganglion":50,
                                 "vascular":15 ]));
        set( "stun_difficulty/ma",7);  
	set( "alignment", -1000 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
	set_c_verbs( ({ "%s右手手刀往%s的咽喉猛力一劈", "%s左手直拳向%s的小腹击来" }) );
        set_skill( "parry",70 );
        set_skill( "shortblade",100 );
        set_skill( "unarmed",100 );
        set_skill("tactic",100);
        set("tactic","melee");
        set( "wealth" , ([ "gold": 100 ]) );
        set( "forgetful", 1);    
        wield_weapon(MOBJ"sound.c");
        equip_armor(MOBJ"karate.c"); 
}
