#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Leather Jackboots","皮革马靴" );
	add( "id",({ "jackboots","boots" }) );
	set_short( "皮革马靴" );
	set_long(@LONG
	这是一双用鹿皮做的长靴，穿起来可是非常舒
	服的喔。
LONG
           );
	set( "unit","双" );
	set( "weight",50 );
	set( "type","feet" );
	set( "material","leather" );
	set( "armor_class",6 );
	set( "value",({ 450,"silver" }) );
}
