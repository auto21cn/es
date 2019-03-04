#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("puty beads ","菩提念珠");
    add("id",({"bead","beads",}) );
    set_short("菩提念珠");
	set_long(@C_LONG
这是一串由千年菩提子做成的念珠, 由於使用很久, 看起来很旧了。
这一串念珠散发出一股宁静的气息, 带给你心灵的平静。
C_LONG
	);
	set( "unit", "串" );
	set( "weight", 15 );
        set("material","wood");
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 180, "gold" }) );
}
