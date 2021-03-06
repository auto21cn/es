#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蚕丝胫甲";

void create()
{
	set_name( "silver leggings", C_NAME );
	add( "id", ({ "leggings" }) );
	set_short( C_NAME );
	set_long(
		"一副闪亮的银色胫甲，这副胫甲是诺达尼亚王室的特约工匠麦尔\n"
		"迪蓝的精心杰作，他曾经很自豪地向人们说过，这套胫甲的防御\n"
		"力除了附上魔法以外，已经无法再更强了。\n"
	);
	set( "unit", "副" );
	set( "type", "legs" );
	set( "material", "knight");
	set( "armor_class", 10);
	set( "weight", 150 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
