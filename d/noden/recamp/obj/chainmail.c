#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "chainmail", "铠甲" );
	add( "id", ({ "chain", "mail" }) );
   set_short( "铠甲" );
	set_long(
		"这件铠甲上有不少被武器砍出来的痕迹，看起来它原来的主人一定\n"
		"身经百战。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 12 );
    set( "special_defense",
           ([ "acid":1, "poison":1 ]) );
	
	set( "weight", 180 );
	set( "value", ({ 80, "silver" }) );
}
