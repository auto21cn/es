#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "archmaster robe", "大国师袍" );
	add( "id", ({ "robe", }) );
	set_short( "大国师袍");
	set_long( 
@C_LONG
这是东方皇帝赐给大国师的长袍，据说是用古时海外某国所进贡的奇异衣料
所制成，有股暗暗的光芒。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 55 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 38 );
	set( "defense_bonus", 5 );
	set( "special_defense" ,
	      ([ "all": 20, "none":10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 2000, "silver" }) );
}
