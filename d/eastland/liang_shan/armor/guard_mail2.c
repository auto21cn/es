#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Gurad mail","红蟹甲");
    add("id",({"plate","mail"}) );
    set_short( "guard mail","红蟹甲");
	set_long(
		"\n",
		"这件战甲由红蟹壳制成，坚硬的表皮应能抵挡一般的攻击．\n"
	);
	set( "unit", "件" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "armor_class", 33 );
        set("material","element");
	set( "defense_bonus", 6 );
	set( "value", ({ 70, "gold" }) );
                                    
}
