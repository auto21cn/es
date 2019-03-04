#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "small cap", "瓜皮小帽" );
	add( "id", ({ "cap" }) );
	set_short( "a small cap", "瓜皮小帽" );
	set_long(
		"You see a small round cap.\n",
		"这是一顶绸缎布面的圆顶小帽，看起来像是有钱人的帽子。\n"
	);
	set( "unit", "顶" );
        set("material","leather");
	set( "type", "head" );
	set( "armor_class", 4 );
	set( "weight", 20 );
	set( "value", ({ 70, "silver" }) );
}
