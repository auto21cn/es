#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Dragon Knight's Lance","����ʿǹ" );
	add( "id",({ "jousting","lance" }) );
	set_short( "����ʿǹ" );
	set_long(@LONG
	����ʿ����ʱ���õ�ǹ���㲽ʱ��ɷ���ǿ��
	������
LONG
		);
	set( "unit","��" );
	set( "type","jousting" );
	set( "weapon_class",50 );
	set( "min_damage",25 );
	set( "max_damage",60 );
//	set( "bleeding",20 );
	set( "weight",200 );
	set( "value",({ 13500,"silver" }) );
//	set( "no_sale",1 );
	set( "nosecond",1 );
	set( "prevent_insert",1 );
}