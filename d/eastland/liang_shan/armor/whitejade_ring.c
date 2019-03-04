#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("white jade ring","羊脂珠玉环");
        add("id",({"ring"}) );
         set_short( "white jade ring","羊脂珠玉环");
	set_long(
"This is a ring made of white jade . \n"
"这是羊脂白玉所制成的指环,具有非凡的防御力\n"
);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","scholar");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "value", ({ 150, "gold" }) );
}
