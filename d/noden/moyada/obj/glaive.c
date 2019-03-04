#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Glaive", "大刀");
	add ("id",({ "blade","glaive","sword",}) );
	set_short("斩肉大刨刀");
	set_long(@C_LONG
这是一把王虎使用的大刀，刀上刻著一条气宇轩昂的龙，
足见其霸气十足。
C_LONG
	);
	
	set( "unit", "把" );
	set_c_verbs( ({ "%s劈向%s",  }) );
 	set( "weapon_class", 29 );
 	set( "nosecond", 1);
	set( "type", "longblade" );
	set( "no_sale", 1);
	set( "min_damage", 17 );
	set( "max_damage", 39 );
	set( "weight", 290 );
	set( "value", ({ 21100, "silver" }) );
}
