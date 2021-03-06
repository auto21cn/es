#include <../takeda.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(13);
	set_name( "Crab warrior", "蟹将" );
	add( "id", ({ "warrior", "crab" }) );
	set_short( "Crab warrior", "蟹将" );
	set_long(
		"\n",
		"这一名战士是龙宫的主要守护者,他会主动追击来犯之入侵者。\n"
	);
	set( "unit", "名" );
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 17 );
	set_skill( "shortblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "block", 90 );
	set( "aggressive", 1 );
        set ("natural_weapon_class1", 18);
        set ("natural_min_damage1", 8);
        set ("natural_max_damage1", 11);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",10);
        wield_weapon(TWEAPON"gurad_sword");
        equip_armor(TARMOR"guard_mail2");
        equip_armor(TARMOR"guard_shield");
}
