#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name( "deer gloves", "鹿皮手套" );
	add( "id", ({ "gloves" }) );
	set_short( "鹿皮手套" );
	set_long(
	"这是一双鹿皮做的手套，通常施毒的人都会带著它，以免自己中毒。\n"
	);
	set( "unit", "双" );
        set("material","leather");
	set( "type", "hands" );
	set( "weight", 30 );
	set( "armor_class", 3 );
 	set( "defense_bonus", 3 );
	set("special_defense",(["poison":30 ]));
	set( "value", ({ 240, "silver" }) );
	set( "extra_skills",(["venomlogy":5]) );
}

