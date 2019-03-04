#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "little wand", "小魔杖" );
	add( "id", ({ "wand" }) );
        set_short( "小魔杖" );
	set_long(@CLONG
    这是一把不起眼的小魔杖，大概只能用来玩玩罢了。
CLONG
	);
	set( "unit", "把" );
	set( "type", "wand" );
        set( "weapon_class", 5 );
        set( "min_damage", 3 );
        set( "max_damage", 6 );
        set( "weight", 40 );
        set( "value", ({ 10, "silver" }) );

	set( "hit_func", "wand_hit" );
        set( "charge_left", 5 );
        set( "max_charge", 5 );
        set( "power_on", 0);
        set( "special_damage_type", "divine" );
        set( "special_damage", 5 );
        set( "special_c_msg", "从杖头发出一道微弱的光芒！" );
}

