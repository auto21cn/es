#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Silk cloth","丝制衣服");
        add("id",({"cloth"}) );
         set_short( "Silk cloth","丝制衣服");
	set_long(
"This is a suit of cloth made of silk meterial.and it is worn \n"
"by Yang's bishop.\n"
"这是一件丝制衣服,通常是 Yang 的牧师所穿的,因此有一种保护力附在身上\n"
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 20 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "evil" :8, "divine":-10 ]) );
	set( "value", ({ 218, "gold" }) );
}
