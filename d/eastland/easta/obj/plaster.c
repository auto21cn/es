#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "plaster", "金创药" );
	set_short( "金创药" );
	set_long("这盒金创药上标示著: 外用药(apply)，严禁服用。\n");
	set( "unit", "盒" );
	set( "heal_apply", 3 );
	set( "duration", 20 );
	set( "weight", 15 );
	set( "value", ({ 6, "gold" }) );
}
