#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red mail", "红鳞甲" );
	add( "id", ({ "mail" }) );
	set_short( "红鳞甲" );
	set_long( 
             @LONG
这件鳞甲是深海怪鱼身上的鳞片用天蚕丝缝制而成。
LONG
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 23 );
	set( "defense_bonus", 5);
	set( "special_defense",
	     ([ "energy":15, "cold":-5 ]) );
	set( "weight", 200 );
	set( "value", ({ 3000, "silver" }) );
}
