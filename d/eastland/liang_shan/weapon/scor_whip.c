#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("tail of scorpion","蝎子尾巴");
       add("id",({"whip","tail",}) );
       set_short("蝎子尾巴");
	   set_long(
	   "这是一只蝎子的尾巴，末端生著锐利的倒刺，也许你可以拿来当武器...\n"
	);
	
	set( "unit", "条" );
 	set( "weapon_class", 25 );
        set("type","whip");
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "weight", 10 );
        set( "value", ({ 1, "silver" }) );
        set( "no_sale", 1 );
    set_c_verbs(({
    "%s挥出一股腥风，打向%s",
    "%s随手一挥，倒刺打向%s",
    "%s高高举起，由空中如蛇般笔直袭向%s",}));
}

