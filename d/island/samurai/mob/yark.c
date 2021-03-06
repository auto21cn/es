#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "samurai yark","武士 约克" );
	add( "id", ({ "yark" }) );
	set_short( "武士 约克" );
	set_long(@AAA
约克是武士队长约修的弟弟,同为兄弟约克的剑术也不在约修之下,而约克
最想做的事就是有一天一定要胜过哥哥约修!!!
AAA
        );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 24 );
        set_perm_stat( "pie", 17 );    
 	set_natural_armor( 55,25 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 30 ); 
        set( "special_defense",([ "all":15,"none":15 ])); 
        set( "aim_difficulty",([ "critical":70,"weakest":10,"ganglion":60,
                                 "vascular":10 ]));
        set( "stun_difficulty/ma",10);  
	set( "alignment", 500 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry",85 );
        set_skill( "longblade",100 );
        set_skill( "tactic",100);
        set("tactic","melee");
        set( "wealth" , ([ "gold": 70 ]) );
        set( "weight", 400 );    
        wield_weapon(MOBJ"dragonlight_sword.c");
        equip_armor(MOBJ"samurai_vest.c");
        equip_armor(MOBJ"samurai_cloak.c");
        equip_armor(MOBJ"samurai_armband.c"); 
}
