#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蚕茧盔甲";

void create()
{
	set_name( "silver platemail", C_NAME );
	add( "id", ({ "plate", "platemail" }) );
	set_short( C_NAME );
	set_long(
		"一套闪亮的银色盔甲，这套盔甲是诺达尼亚王室的特约工匠麦尔\n"
		"迪蓝的精心杰作，他曾经很自豪地向人们说过，这套盔甲的防御\n"
		"力除了附上魔法以外，已经无法再更强了。\n"
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "knight");
	set( "armor_class", 40 );
	set( "weight", 370 );
	set( "value", ({ 330, "gold" }) );
	set( "no_sale",1 );
}
