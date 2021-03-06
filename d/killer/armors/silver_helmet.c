#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蚕茧头盔";

void create()
{
	set_name( "silver helmet", C_NAME );
	add( "id", ({ "helmet" }) );
	set_short( C_NAME );
	set_long(
		"一顶闪亮的银色头盔，这顶头盔是诺达尼亚王室的特约工匠麦尔\n"
		"迪蓝的精心杰作，他曾经很自豪地向人们说过，这顶头盔的防御\n"
		"力除了附上魔法以外，已经无法再更强了。\n"
	);
	set( "unit", "顶" );
	set( "type", "head" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "extra_skills", ([ "tactic":10 ]) );
	set( "weight", 70 );
	set( "value", ({ 250, "gold" }) );
	set( "no_sale", 1);
}
