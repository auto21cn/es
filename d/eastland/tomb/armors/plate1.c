#include "../almuhara.h"

inherit ARMOR;

void create()
{
        set_name("Holy plate","东天圣甲");
        add("id",({"plate","platemail"}) );
        set_short( "东天圣甲");
	set_long(
"这是一副由某种奇异金属所造的铠甲,可以保护你抵抗敌人的攻击。当你面对邪恶的
敌人时，它可以提供更好的防护力。\n"
	);
	set( "unit", "件" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 35 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([ "evil" : 20 ]) );
	set( "value", ({ 320, "gold" }) );
}
