#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name( "Fun-Tain Halberd","方天战戟" );
	add( "id",({ "polearm","halberd" }) );
	set_short( "方天战戟" );
	set_long(@LONG
	这是蜥蜴人战事指挥官才有资格使用的武器。
LONG
		);
	set( "unit","把" );
	set( "type","polearm" );
	set( "weapon_class",40 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",130 );
	set( "value",({ 6750,"silver" }) );
	set( "prevent_insert",1 );
}