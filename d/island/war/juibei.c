#include "../island.h"

inherit IWAR"i_warvalue";

void create()
{
	::create();
	set_level(19);
	set_name( "Samurai Juibei","十兵卫" );
	add( "id", ({ "samurai","juibei" }) );
	set_short( "武士守备队长 十兵卫" );
	set_long(@AAA
十兵卫是武士边境守备队的队长，负责监视蜥蜴人及魔族军队的动向
AAA
);
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "justice", 15 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 48,10 );
	set( "natural_weapon_class1", 15 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 ); 
	set( "natural_weapon_class2", 5 );
	set( "natural_min_damage2", 6 );
	set( "natural_max_damage2", 12 );
        set( "special_defense",([ "all":30,"none":30 ])); 
        set( "aim_difficulty",([ "critical":20,"weakest":20,"ganglion":50,
                                 "vascular":15 ]));
        set( "stun_difficulty",15);  
	set( "alignment", -2000 );
	set( "killer", 1);
        set_skill( "parry",100 );
        set_skill( "two-weapon",100);
        set_skill( "longblade",100 );
        set_skill( "tactic",100);
        set("tacitc","berserk");
        set( "wealth" , ([ "gold": 250 ]) );
        wield_weapon(IWARO"moon_sword.c");
        wield_weapon2(IWARO"star_sword.c");
        equip_armor( IWARO"samurai_cloak.c");
        equip_armor( IWARO"samurai_cloth.c");
        equip_armor( IWARO"samurai_mark.c");
        equip_armor( IWARO"samurai_armband.c");
        set("chat_chance", 20 );
        set("att_chat_output", ({
        "十兵卫大喝道：你们这些违反盟约的骗子，我要宰光你们！！！\n",
        "十兵卫说道：兄弟们：给我杀光他们，不要跟他们客气！！！！\n",
        "十兵卫说道：我们武士团大军就要到了，你们一定会後悔的！！\n"
        }));
             
}
