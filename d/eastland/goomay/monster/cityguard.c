
#include <../goomay.h>

inherit Army;

void create()
{
	::create();
	set_level(11);
	set_name( "cityguard", "镇口守卫" );
	add( "id", ({ "guard" }) );
	set_short( "镇口守卫" );
	set_long(
		"你看到一个守卫古梅镇镇口的卫兵。\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 500 );
	set_natural_armor( 30, 10 );
	set_natural_weapon( -2, 1, 5 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "kar", 15 );
	set_skill( "shortblade", 60 );
	set_skill( "parry", 70 );
	set( "hit_points", 350 );
	set( "max_hp", 350 );
	set( "wealth/gold", 20 );
	set( "special_defense", ([ "all": 20 ]) );
	set("defense_type","berserk");
	wield_weapon( Obj"shortsword01" );
	equip_armor( Obj"braso_mail" );
	equip_armor( Obj"steel_helm" );
}
