#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(14);
	set_name("captain","山贼小队长");
	add ("id", ({ "thief","bandit" }) );
	set_short("山贼小队长");
	set_long(
		"山贼小队长是梁山山贼的基本作战单位的领导人，手下通常指挥五\n"
		"到十名的山贼。通常是从众多山贼中选出武艺精良且孚众望者居之\n");
	set_perm_stat("dex", 12);
	set_perm_stat("kar", 15);
	set_perm_stat("str", 11);
        set("unit","位");
	set_skill( "longblade", 60 );
	set_skill( "parry", 50 );
	set_skill( "anatomlogy", 50 );
	set( "aiming_loc", "weakest" );
	set( "attack_skill","monk/general/tai_zuo");
	set( "max_fp", 100 );
	set( "max_hp", 380 );
	set( "hit_points", 380 );
	set( "force_points", 100 );
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", -300 );
	set( "wealth/gold", 32 );
	set_natural_armor( 10, 10 );
	set_natural_weapon( 12, 7, 15 );
        set ("special_defense",(["fire":2,"cold":-2,"magic":2]));
        wield_weapon(TWEAPON"yanlin");
        equip_armor(TARMOR"bandit_armor");
}               

