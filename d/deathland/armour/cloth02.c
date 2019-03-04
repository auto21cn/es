#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Silk cloth","丝制衣服");
        add("id",({"cloth"}) );
         set_short( "Silk cloth","丝制衣服");
	set_long(
"This is a suit of cloth made of silk meterial. \n"
"这是一件丝制衣服.\n"
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 16 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "evil":4, "divine":-6 ]) );
	set( "value", ({ 187, "gold" }) );
}
