#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "magical robe", "魔法长袍" );
	add( "id", ({ "robe" }) );
	set_short( "魔法长袍" );
	set_long( @C_LONG
    莫亚达镇上的魔法师最喜欢穿的长袍, 据说附有一些魔力。
C_LONG
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 4 );
	set( "special_defense",
	      ([ "magic":5, "fire":-3 ]) ); 
        set( "weight", 50 );
	set( "value", ({ 1500, "silver" }) );
}
