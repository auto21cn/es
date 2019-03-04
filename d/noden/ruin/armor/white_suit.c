#include "../lilia.h"

inherit ARMOR;

void create()
{
        set_name("white cloth","白衣");
        add("id",({"cloth"}) );
	set_short( "白衣" );
        set_long(
"这是一件白色的布衣\n"
        );
        set( "unit", "件" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 10 );
        set( "defense_bonus", 2 );
        set( "value", ({ 520, "silver" }) );
}
