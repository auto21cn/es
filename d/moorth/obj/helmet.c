#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed visor helm", "合金覆面头盔" );
	add( "id", ({ "visor helm", "visor", "helm" }) );
	set_short( "an alloyed visor helm", "合金覆面头盔" );
	set_long(
		"You see an alloyed visor helm. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"这是一面用某种不知名合金打造的覆面头盔，看起来相当重。\n"
	);
	set( "unit", "具" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "armor_class", 6 );
	set( "weight", 80 );
	set( "value", ({ 580, "silver" }) );
}
