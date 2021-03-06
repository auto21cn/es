#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "Black Panda","大黑熊" );
	add( "id",({ "panda" }) );
	set_short( "大黑熊" );
	set_long(@LONG
一头具大强壮的黑熊正在寻找猎物，你最好小心点，千
万别惊动它，否责它会把你大卸八块，拿去喂它的小孩。
LONG
                );
	set( "killer",1 );
	set( "alignment",-750 );
	set( "gender","female" );
	set( "unit","头" );
	set_perm_stat( "dex",22 );
	set_perm_stat( "str",30 );
	set_perm_stat( "int",25 );
	set_perm_stat( "con",20 );
	set_perm_stat( "pie",10 );
	set_perm_stat( "kar",25 );
	set_skill( "unarmed",80 );
	set_skill( "dodge",80 );
	set( "special_defense",([ "sleet":50,"none":60,"fire":-20 ]) );
	set( "max_hp",800 );
	set( "hit_points",800 );
	set( "wealth",([ "gold":35 ]) );
	set_natural_weapon( 75,30,45 );
	set_natural_armor( 115,40 );
	set( "natural_weapon_class2",70 );
	set( "natural_min_damage2",20 );
	set( "natural_max_damage2",38 );
	set( "weight",800 );
	set( "unbleeding",1 );
	set_c_verbs( ({ "%s用它肥厚的手掌向%s挥去","%s张开它长满利牙的嘴向%s咬去" }) );
	set_c_limbs( ({ "额头","胸膛" }) );
}
