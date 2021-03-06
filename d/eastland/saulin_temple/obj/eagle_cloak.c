#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silver cloak", "银鹰之翼" );
	add( "id", ({ "cloak" }) );
	set_short( "银鹰之翼" );
	set_long(@C_LONG
银鹰据说是居住在高山顶的极稀有生物，它的羽毛据说十分的珍贵。
银鹰之翼是用银鹰的羽毛做成的袍子，又保暖又有极佳的保护效果。
C_LONG
                );
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "armor_class", 8 );
	set( "material", "leather" );
	set( "defense_bonus", 4 );
	set( "weight", 100 );
	set( "value", ({ 2530, "silver" }) );
}
