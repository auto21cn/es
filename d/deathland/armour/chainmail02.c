#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Ironsteel chainmail","铁钢□甲");
        add("id",({"chainmail"}) );
         set_short( "a ironsteel chainmail","铁钢□甲");
	set_long(
"This is a suit of chainmail made of iron steel,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副由铁钢造的□甲,可以保护你抵抗敌人的攻击\n"
	);
	set( "unit", "件" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 22 );
	set( "defense_bonus", 0 );
	set( "value", ({ 1470, "silver" }) );
}
