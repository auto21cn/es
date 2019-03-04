#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "round cap", "圆顶小帽" );
	add( "id", ({ "cap" }) );
	set_short( "圆顶小帽" );
	set_long("这是一顶绸缎布面的圆顶小帽，看起来像是有钱人的帽子。\n");
	set( "unit", "顶" );
	set( "type", "head" );
	set( "material", "cloth" );
	set( "armor_class", 4 );
	set( "weight", 20 );
	set( "value", ({ 70, "silver" }) );
}
