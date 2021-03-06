#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Samurai captain yashu","武士队长 约修" );
	add( "id", ({ "captain","yashu" }) );
	set_short( "武士队长 约修" );
	set_long(@AAA
你眼前的正是武士团的队长，虽然他长的很斯文，但要知道剑术高低是和长相无关的
目前他为了如何再增强武士团的战力而烦恼中！！！
AAA
   );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 24 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 15 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",600 );
        set( "hit_points",600 );
 	set_natural_armor( 50,25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 40 ); 
        set( "time_to_heal",35);
        set( "special_defense",([ "all":30,"none":30 ])); 
        set( "aim_difficulty",([ "critical":60,"weakest":40,"ganglion":50,
                                 "vascular":45 ]));
        set( "stun_difficulty/ma",35);  
	set( "alignment", 1000 );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "tactic",100);
        set("tacitc","berserk");
        set( "wealth" , ([ "gold": 150 ]) );
        set( "tactic_func", "att_gonfus");
        wield_weapon(MOBJ"sound_blade.c");
        equip_armor(MOBJ"night_cloak.c");
        equip_armor(MOBJ"a_shu_la.c");
        equip_armor(MOBJ"mark.c");
             
}

int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
     "\n约修喝到：接下我的必杀剑吧\n"+
     "约修双手齐挥，舞出一片剑幕，你可以隐约的看到阿修罗的样子！！　\n\n"+
     "约修大喝一声：接我的″蝶～舞～阿～修～罗～斩″\n\n"+
     "那一面剑幕一起向"+victim->query("c_name")+"罩下，并划下了数十道伤口！！\n"
      );
      dam = 30 + random(25);
      victim->receive_special_damage("cold", dam );
      report(this_object(),victim);
      return 1;
      
}
