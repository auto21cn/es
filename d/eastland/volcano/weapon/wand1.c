#include "../oldcat.h"

inherit WEAPON;

void create()
{
	set_name("storm wand", "狂风杖");
	add ("id",({ "wand",}) );
	set_short("狂风杖");
	set_long(
        "这是一把能呼唤「风暴」的魔杖，你隐约可以看见杖头附近的空气有些扰动。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
	set( "type", "wand" );
        set( "min_damage", 17 );
	set( "max_damage", 30 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 8 );
	set( "max_charge", 8 );
	set( "special_damage_type", "energy" );
	set( "special_damage", 80 );
	set( "special_c_msg", "招来一阵风暴，使所有的敌人皆陷入风暴之中。\n" );
}
