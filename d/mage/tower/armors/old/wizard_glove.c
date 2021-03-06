#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's gloves", "巫师手套" );
	add( "id", ({ "glove", "gloves", }) );
	set_short( "a wizard's gloves", "巫师手套" );
	set_long( @TOPIC
	The pair of gloves used by wizard Rashudi. It is made by normal cloth,
but spreads a special power of magic.
TOPIC
    , @C_TOPIC
	拉修帝习惯戴的手套，虽然只是用普通的布做的，但散发出一股魔力。
C_TOPIC
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "defense_bonus", 5 );
	set( "special_defense",
	    ([ "acid":10, "poison":5 ]) );
	set( "extra_skills", ([ "target":10 ]) );    
	set( "weight", 10 );
	set( "no_sale", 1);
	set( "value", ({ 2500, "silver" }) );
}
