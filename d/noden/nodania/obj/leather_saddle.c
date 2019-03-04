#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather saddle", "皮革马鞍" );
	add( "id", ({ "saddle" }) );
	set_short( "皮革马鞍" );
	set_long(
	"这是一副普通的皮革制马鞍，骑士们都会为自己的爱马选择舒适的马鞍。\n" 
	);
	set( "type", "saddle" );
	set( "material", "leather" );
	set( "armor_class", 3 );
	set( "weight", 75 );
	set( "value", ({ 230, "silver" }) );
}
