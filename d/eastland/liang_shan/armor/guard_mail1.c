#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Soft mail","软虾背心");
    add("id",({"plate","mail"}) );
    set_short( "soft mail","软虾背心");
	set_long(
		"\n",
		"这件战甲由柔软的虾壳制成，柔韧的表皮应能发挥以柔克刚的效果．\n"
	);
	set( "unit", "件" );
	set( "weight", 140 );
	set( "type", "body" );
	set( "armor_class", 31 );
        set("material","element");
	set( "defense_bonus", 3 );
	set( "value", ({ 77, "gold" }) );
                                    
}
