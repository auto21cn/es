#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "murasame blade", "����" );
	add( "id", ({ "murasame", "blade" }) );
   set_short( "��������" );
	set_long(
		"������ǰ�����ɢ������ɭɭ�����ĳ������Ƕ������õġ���������������\n"
		"��ɢ����һ������������������ȥɱ�����ˡ�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 90 );
   set( "weapon_class", 45 );
   set( "min_damage", 18 );
	set( "max_damage", 47 );
   set( "bleeding", 20 );
	set( "value", ({ 700, "silver" }) );
// set( "extra_stats", ([ "kar" : -7 ]) );
}