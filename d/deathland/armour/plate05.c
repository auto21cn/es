#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("gold plate","金铠甲");
        add("id",({"plate","platemail"}) );
         set_short( "a gold plate","金铠甲");
	set_long(
"This is a suit of plate make of gold ,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副由黄金打造的铠甲,可以保护你抵抗敌人的攻击\n"
	);
	set( "unit", "件" );
	set( "weight", 400 );
	set( "type", "body" );
	set( "armor_class", 32 );
	set( "defense_bonus", 0 );
	set( "material", "heavy_metal" );
	set( "value", ({ 680, "gold" }) );
}
