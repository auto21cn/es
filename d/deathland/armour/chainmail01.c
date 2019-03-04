#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril chainmail","矮人米苏理□甲");
        add("id",({"chainmail"}) );
         set_short( "a dwarvern mithril chainmail","矮人米苏理□甲");
	set_long(
"This is a suit of chainmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副由米苏理金属造的□甲,可以保护你抵抗敌人的攻击\n"
	);
	set( "unit", "件" );
	set( "weight", 230 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
	set( "value", ({ 200, "gold" }) );
}
