#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "large scissors", "大花剪" );
	add( "id", ({ "scissors", "scissor" }) );
	set_short( "大花剪" );
	set_long(@LONG
这是一把用来修剪植物的大剪刀，上面沾有些许灰尘。
LONG
	);
	set( "type", "shortblade" );
	set( "weapon_class", 20 );
	set( "min_damage", 15 );
	set( "max_damage", 22 );
	set( "weight", 80 );
	set( "value", ({ 1000, "silver" }) );
	set_c_verbs( ({ "的%s往%s一夹" }) );
}
