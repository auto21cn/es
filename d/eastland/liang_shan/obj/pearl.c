#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "Moon pearl", "夜明珠" );
	add( "id", ({ "pearl" }) );
	set_short( "moon pearl", "夜明珠" );
	set_long(
		".\n",
		"这是一颗罕见的大珍珠，发出梦幻般的光芒，据传是大蚌精\n"
		"吸收月光精华的结晶。\n"
	);
	set( "unit", "颗" );
	set( "light", 1 );
	set( "weight", 30 );
	set( "value", ({ 3000, "silver" }) );
	set( "no_sale", 1 );
}
