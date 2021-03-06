#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
	::create();
	set("lvlimit",15);
	set_level(7);
	set_name( "two-bag beggar", "二袋弟子" );
	set("id",({"two","beggar"}));
	set_short( "丐帮 二袋弟子" );
	set_long(@C_LONG
二袋弟子正辛勤地练武功。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 7 );
	set_perm_stat( "dex", 7 );
	set_skill( "dodge", 50 );
	set( "special_defense", ([ "all": 2 ]) );
	set("race","human");
	set( "gender", "male" );
	set( "alignment", 0 );
	set_natural_armor( 10, 2 );
	set_natural_weapon( 20, 10, 15 );
	set( "natural_weapon_class2", 10 );
	set( "natural_min_damage2", 5 );
	set( "natural_max_damage2", 10 );
	set( "wealth/gold", 10 );
	set_c_verbs( ({ "%s踏步向前，一记直拳打向%s", "%s左腿往%s一踢" }) );
}
