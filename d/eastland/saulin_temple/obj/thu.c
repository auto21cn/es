#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
    set_name("king-kong thu","金刚杵");
    add("id",({"mace","thu"}) );
    set_short("金钢杵");
    set_long(
		"由金刚砂和黑银混合制成的金刚杵, 相传是大力金刚用来降魔伏妖的法器。\n"
    );
	set( "unit", "把" );
 	set( "weapon_class", 37 );
	set("type","bo");
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "weight", 230 );
        set( "nosecond",1); 
	set( "value", ({ 200, "gold" }) );
}
