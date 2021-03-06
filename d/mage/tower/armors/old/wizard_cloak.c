#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's cloak", "巫师斗蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "a wizard's cloak", "巫师斗蓬" );
	set_long( @LONG
	This cloak is used by wizard Rashudi. It is made by magical cloth and 
spreads a wanderful power of magic.
LONG
    , @C_LONG
	魔导士拉修帝惯於穿著的斗蓬，由於用被附与魔法的布织成，散发出一股不可抵
抗的魔力，据说拥有抵抗各种魔法的能力。
C_LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 10 );
	set( "special_defense",
          ([ "electric":5, "energy":5, "mental":10 ]) );
    set( "extra_skill", ([ "elemental":10 ]) );     
	set( "weight", 30 );
	set( "no_sale", 1);
	set( "value", ({ 5800, "silver" }) );
}
