#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("shoes","六合靴");
	add( "id", ({ "shoes", "shoe", }) );
	set_short( "a shoes", "六合靴" );
	set_long(@C_TOPIC
用普通的皮革做的，但由於形式别出心裁，风格与众不同，所以博得六合之美称。
C_TOPIC
	);
	set( "unit", "双" );
	set( "type", "feet" );
	set( "material", "leather" );
	set( "armor_class", 5 );
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "all":5, "none":2 ]) );     
	set( "weight", 40 );
	set( "no_sale", 1);
	set( "value", ({ 1500, "silver" }) );
}
