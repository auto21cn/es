#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Ninja Kola","忍者 葛拉" );
	add( "id", ({ "ninja","kola" }) );
	set_short( "忍者 葛拉" );
	set_long(@AAA
忍者葛拉，武士团黑暗力量的代表，藉由葛拉所率领的忍者部队在暗地的行动，以
及武士团的正面作战，这就是武士团的必胜方程式，而忍者首领葛拉的武艺号称武
士城堡中最强的，你如果不信的话可以找他试一试！！！
AAA
        );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );
        set( "time_to_heal",20 );    
        set( "max_hp",1000 );
        set( "hit_points",1000 );
 	set_natural_armor( 70,20 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":70,"ganglion":100,
                                 "vascular":35 ]));
        set( "stun_difficulty",10);  
	set( "alignment", -1000 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry", 80 );
        set_skill( "longblade", 100 );
        set_skill( "unarmed", 100 );
        set_skill( "dodge", 80 );
        set_skill( "tactic", 100 );
        set( "tactic","melee");
        set( "wealth" , ([ "gold": 100 ]) );
        set("chat_chance",15);
        set("att_chat_output",({@AAA
        
葛拉狂笑道：你觉得你的经验值够多吗？够你死吗？那我就成全你吧！！

AAA
,@BBB

葛拉说道：我是很慷慨的，可以免费送你去远风镇不收你半毛钱喔！！

BBB
}));    
        wield_weapon(MOBJ"evil_sword.c");
        equip_armor(MOBJ"dragon_chainmail.c");
        equip_armor(MOBJ"samurai_boots.c"); 
}
