#include  <mudlib.h>

inherit ARMOR;

string C_NAME="天蚕丝鞋";

void create()
{
        set_name("silver boots", C_NAME);
        add( "id", ({ "boots" }) );
	set_short( C_NAME );
        set_long(
                "一双闪亮的银色靴子，这双靴子是诺达尼亚王室的特约工匠麦尔\n"
                "迪蓝的精心杰作，他曾经很自豪地向人们说过，这双靴子的防御\n"
                "力除了附上魔法以外，已经无法再更强了。\n"
        );
        set( "unit", "双" );
        set( "type", "feet" );
        set( "material", "knight");
        set( "extra_skills", ([ "defend":10 ]) ); 
        set( "armor_class", 10 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1); 
}
