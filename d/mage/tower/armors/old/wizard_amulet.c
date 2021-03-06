#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's amulet", "巫师护身符" );
	add( "id", ({ "amulet" }) );
	set_short( "a wizard's amulet", "巫师护身符" );
	set_long(
		"This is Rashudi's magical amulet. You can see many symbols\n"
		"of magical shield on it.\n",
		"这个护身符是拉修帝最常带在身边的，上面画满了各种魔法防御的咒文。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 10 );
	set( "special_defense",
	     ([ "fire":10, "cold":10, "electric":5, "energy":5 ]) );
	set( "extra_skills", ([ "meditate":10 ]) );     
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 5500, "silver" }) );
}
