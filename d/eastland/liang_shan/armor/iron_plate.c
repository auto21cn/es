#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("iron plate","裹金生铁甲");
    add("id",({"plate","mail"}) );
    set_short( "iron plate","裹金生铁甲");
	set_long(
		"This is a suit of mail made of iron meterial.\n",
		"这是一件看来旧旧的金边铁甲胄，虽然年代久远但保存完好，\n"
		"穿上它仍然可以上场作战．\n"
	);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","heavy_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 166, "gold" }) );
}
