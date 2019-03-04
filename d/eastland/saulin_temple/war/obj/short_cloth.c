
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("fighters' cloth","青布短打");
        add("id",({"cloth"}) );
         set_short("青布短打");
        set_long(
"这是一件打斗专用的衣服，穿起来会很神气... 只是神气而已。\n"
        );
        set( "unit", "件" );
        set( "weight", 70 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
	set( "special_defense", ([ "mental":2, "fire":-2, "acid":-2 ]) );
        set( "value", ({ 120, "silver" }) );
}
