#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "white plaster", "云南白药" );
	add( "id", ({ "plaster", "yun-nan white plaster" }) );
	set_short( "云南白药" );
	set_long(
	"这是由东方大国进口的云南白药，盒子上标示著: 外用药(apply)，严禁服用。\n"
	);
	set( "unit", "盒" );
	set( "heal_apply", 5 );
	set( "duration", 30 );
	set( "weight", 15 );
	set( "value", ({ 15, "gold" }) );
}
