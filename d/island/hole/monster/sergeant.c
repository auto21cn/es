#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(10);
	set_name( "Lizardman Sergeant", "蜥蜴人班长" );
	add( "id", ({ "lizardman","sergeant" }) );
	set_short( "蜥蜴人班长" );
	set_long(@LONG
你看到的是一位战场上的老兵，他正带领著班
兵四处杀敌，企图歼灭敌人
LONG
	);
	set( "unit", "名" );
	set( "race", "lizardman" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set( "natural_armor",40 );
	set( "natural_defense_bonus",12 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 15 );
	set( "wealth/silver", 50 );
//	set( "aggressive", 1 );
//	set( "pursuing", 1 );
//	set( "moving", 1 );
//	set( "speed", 30 );
	set( "tactic","melee" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 20 );
	set_skill( "shortblade", 60 );
	set_skill( "parry", 60 );
	set_skill( "block", 60 );
	set_skill( "tactic", 60 );
	set_skill( "defend", 60 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"\n蜥蜴人班长大叫: 小子真大胆，敢向我挑战！\n\n",
	}) );
	wield_weapon( HWEAPON"shortsword" );
	
}


