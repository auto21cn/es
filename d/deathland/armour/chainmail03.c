#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("gray chainmail","灰色□甲");
        add("id",({"chainmail"}) );
        set_short( "a gray chainmail","灰色□甲");
	    set_long(
  "这是一副曾经被许\多士兵穿过的□甲,过了这麽多年已经变成灰色了\n"
	);
	set( "unit", "件" );
	set( "weight", 230 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 15 );
	set( "defense_bonus", 0 );
	set( "value", ({ 400, "silver" }) );
}
