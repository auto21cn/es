#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Silvery Lance","银色长枪" );
	add( "id",({ "lance" }) );
	set_short( "银色长枪" );
	set_long(@LONG
	这是把为蜥蜴人骑士特制的长枪，整把枪是一体
	成形的，完全没有接缝，重心的位置也恰到好处
	，是把很顺手的兵器。
LONG
		);
	set( "unit","把" );
	set( "type","jousting" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",38 );
	set( "weight",200 );
	set( "value",({ 1370,"silver" }) );
//	set( "no_sale",1 );
}