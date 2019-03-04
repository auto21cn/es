#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Bulansido Sword","布伦希多剑" );
	add( "id",({ "sword" }) );
	set_short( "布伦希多剑" );
	set_long(@LONG
	这把剑象徵著蜥蜴人族群中至高无上的权力，
	只要谁拥有它，便可以成为蜥蜴人的领袖。这
	是传说中连接天界与地界的圣剑，据说会带来
	胜利与荣耀。
LONG
	);
	set( "unit","把" );
	set( "type","longblade" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",150 );
	set( "value",({ 5600,"silver" }) );
//	set( "no_sale",1 );
//	set( "nosecond",1 );
}