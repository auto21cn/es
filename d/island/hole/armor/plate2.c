#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Plate","战神铠甲" );
	add( "id", ({ "plate" }) );
	set_short( "战神铠甲" );
	set_long(@LONG
	这是蜥蜴人自古代流传至今的战甲。这件战甲
	只有蜥蜴人领袖才有资格穿，因为能当上蜥蜴
	人领袖的人，必定是个骁勇善战的武士。
LONG
           );
	set( "unit","件" );
	set( "weight",130 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",36 );
	set( "defense_bonus",8 );
	set( "value",({ 1440,"silver" }) );
//	set( "no_sale",1 );
}
