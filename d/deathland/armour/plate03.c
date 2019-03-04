#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("black mithril plate","黑色米苏理铠甲");
        add("id",({"plate","platemail"}) );
         set_short( "a black mithril plate","黑色米苏理铠甲");
	set_long(
"This is a suit of plate worn by molader royality ,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副矮人王族历代相传的铠甲,可以保护你抵抗敌人的攻击\n"
	);
	set("no_sale",1);
	set( "unit", "件" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([ "electric": 8 ]) );
	set( "value", ({ 320, "gold" }) );
}
