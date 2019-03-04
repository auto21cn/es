#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "diamond key", "钻石钥匙" );
	add( "id", ({ "key" }) );
	set_short( "钻石钥匙" );
	set_long(
		"这是用钻石琢磨出来的钥匙。\n"
	);
	set( "to_lock", "DIAMONDKEY" );
	set( "weight", 3 );
	set( "value", ({ 50, "silver" }) );
	set( "no_sale", 1 );
}
