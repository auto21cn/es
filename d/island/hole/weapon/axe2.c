#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Long Axe","����ս��" );
	add( "id",({ "axe" }) );
	set_short( "����ս��" );
	set_long(@LONG
	һ�ѳ���ս����
LONG
	);
	set( "unit","��" );
	set( "type","axe" );
	set( "weapon_class",32 );
	set( "min_damage",22 );
	set( "max_damage",36 );
//	set( "bleeding",10 );
	set( "weight",150 );
	set( "value",({ 1080,"silver" }) );
}