#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("beholder globe","眼魔护盾圆球");
        add("id",({"globe"}) );
         set_short( "a beholder globe","眼魔护盾圆球");
	set_long(
"一个球状的反物质,像是一种护盾产生器\n"
	);
	set( "echo_chain_need",1);
	set( "unit", "种" );
	set( "weight", 110 );
	set( "type", "globe" );
	set( "material", "element" );
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "fire":5, "cold":5, "electric":5, "energy":5, "divine":-20 ]) ); 
	set( "value", ({ 48, "gold" }) );
 //        set( "no_sale", 1 );
}
