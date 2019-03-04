#include "../oldcat.h"

inherit WEAPON;

void create()
{
	set_name("elder's wand", "���Ϸ���");
	add ("id",({ "wand",}) );
	set_short("���Ϸ���");
	set_long(
        "����һ���ܽ������ߵ�ħ����������ЧӦ�õ�ħ�ȡ�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 41 );
	set( "type", "wand" );
        set( "min_damage", 19 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "value", ({ 5000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "energy" );
	set( "special_damage", 80 );
	set( "special_c_msg","����ʩ���ߵ�ħ����Դ������һ��ǿ�����������������������\n�ᴩ���еĵ��ˡ�\n" );
}