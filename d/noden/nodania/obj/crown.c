#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("crown", "����");
	set_short("�ƽ�����");
	set_long(
    "����һ�������������ڣ�������������������解�������ʮ������\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "heavy_metal");
	set( "armor_class", 3 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "fire":5, "cold":-8, "mental":5, "energy":-6 ]) );
	set( "value", ({ 3100, "gold" }) );
	set( "weight", 40 );
	set( "no_sale", 1);
}