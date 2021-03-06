#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Chou", "周总镖头" );
	set_short( "周总镖头" );
	set_long("周总镖头刚从京城保了一趟镖回来，现在正在这里喝酒休息。\n");
	set( "unit", "名" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 80 );
	set_skill( "thrusting", 80 );
	set_skill( "two-weapon", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "gender", "male" );
	set( "alignment", 300 );
	set_natural_armor( 75, 30 );
	set_natural_weapon( 8, 5, 10 );
	set( "natural_weapon_class2", 8 );
	set( "natural_min_damage2", 5 );
	set( "natural_max_damage2", 10 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s踏步向前，一记直拳打向%s", "%s左腿往%s一踢",
		"%s使一招「沙僧拜佛」，右拳打向%s", "%s往前一纵，左足往%s踢去",
		"%s一记「左右逢源」，双拳直取%s", "%s使一招「钟鼓齐鸣」，双拳往%s打去",
		"%s一招「声东击西」，右足点向%s", "%s一招「猛虎出闸」，左拳如风，直取%s",
		"%s使一记「黑虎偷心」，右拳直击%s" }) );

	wield_weapon( "/d/eastland/haiwei/obj/pen" );
	wield_weapon2( "/d/eastland/haiwei/obj/pen" );
}
