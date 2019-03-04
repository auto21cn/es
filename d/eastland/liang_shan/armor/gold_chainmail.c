#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("gold chainmail","锁子黄金甲");
    add("id",({"chainmail","mail"}) );
    set_short( "gold chainmail","锁子黄金甲");
	set_long(
		"This is a suit of chainmail made of gold meterial.\n",
		"这是一件金光闪闪的□甲,相传是当年齐天大圣的装备之一，虽然它\n"
		"是黄金制成，但不知为何非常的轻巧．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 130 );
	set( "type", "body" );
	set( "armor_class", 40 );
        set("material","heavy_metal");
	set( "defense_bonus", 5 );
	set( "value", ({ 290, "gold" }) );
}
