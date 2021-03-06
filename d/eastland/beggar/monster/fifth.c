#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "five-bag beggar", "五袋弟子" );
	set("id",({"five","beggar"}));
	set_short( "丐帮 五袋弟子" );
	set_long(@C_LONG
五袋弟子正辛苦的听从七袋弟子的指导。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 12 );
	set_skill( "dodge", 50 );
	set( "special_defense", ([ "all": 10 ]) );
	set("race","human");
	set( "gender", "male" );
	set( "alignment", 0 );
	set_natural_armor( 15, 4 );
	set_natural_weapon( 20, 13, 15 );
	set( "natural_weapon_class2", 20 );
	set( "natural_min_damage2", 10 );
	set( "natural_max_damage2", 15 );
	set( "wealth/gold", 30 );
	set_c_verbs( ({ "%s踏步向前，一记直拳打向%s", "%s左腿往%s一踢",
		"%s使一招「沙僧拜佛」，右拳打向%s", "%s往前一纵，左足往%s踢去" }) );
}
