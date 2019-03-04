#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "green cloak", "绿斗蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "绿斗蓬" );
	set_long( 
@LONG
这是□□所穿著的斗蓬，其实只是一块绿色的布，但这是从□□幼年时就穿到现
在，随著主人一起修炼，已经有一种灵性，对於一些魔法有较强的抗力。
LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "mage");
	set( "armor_class", 5 );
	set( "defense_bonus", 6 );
	set( "extra_skills", ([
	  "black-magic" : 10, "white-magic" : -10, "elemental" : 5, ])
	);
	set( "special_defense", ([
	  "cold" : 30, "electric" : 20, "fire" : -10, ])
    );
	set( "no_sale", 1);
	set( "weight", 40 );
	set( "value", ({ 1000, "silver" }) );
}
