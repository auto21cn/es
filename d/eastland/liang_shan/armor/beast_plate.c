#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("beast plate","连环兽面□猊铠");
    add("id",({"plate","mail"}) );
    set_short( "beast plate","连环兽面□猊铠");
	set_long(
		"This is a plate called best_plate....\n",
		"这是用一种叫□猊的猛兽皮制成的战甲，这种猛兽皮硬如石，生性\n"
		"凶猛，只有先拔下爪子挖去血肉才能得皮，因此这甲可是无价之宝．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "armor_class", 38 );
        set("material","leather");
	set( "defense_bonus", 6 );
	set( "value", ({ 275, "gold" }) );
}
