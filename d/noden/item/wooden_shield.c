#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "wooden shield", "木盾" );
	add( "id", ({ "shield"  }) );
   set_short( "木盾" );
	set_long(
		"一面坚硬的木制盾牌，上面画了一只张牙舞爪的火龙。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "wood" );
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "value", ({ 60, "silver" }) );
}
