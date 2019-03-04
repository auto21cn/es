#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Magic Chabok","魔法长鞭" );
	add( "id",({ "chabok","whip" }) );
	set_short( "魔法长鞭" );
	set_long(@LONG
	一把用藤蔓编成的长鞭，经过蜥蜴人祭司--拉
	索达--长年用魔法浸渍的结果，使得它拥有特
	殊的魔力。
LONG
	);
	set( "unit","把" );
	set( "type","whip" );
	set( "weapon_class",33 );
	set( "min_damage",15 );
	set( "max_damage",30 );
	set( "weight",120 );
	set( "value",({ 1280,"silver" }) );
	set_c_verbs( ({ "%s向%s猛抽一鞭" }) );
}