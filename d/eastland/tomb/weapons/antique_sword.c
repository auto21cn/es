#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Antique Sword", "古剑" );
    add("id", ({"sword"}) );
    set_short("古剑「苍松」");
	set_long(
           "一把造型古意盎然的长剑，在剑锷处铸了两个小字  --- 「苍松」\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 32 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 34 );
	set( "weight", 90 );
	set( "value", ({ 250, "gold" }) );
}

