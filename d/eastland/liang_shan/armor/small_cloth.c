#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("general cloth","麻衫");
    add("id",({"cloth"}) );
    set_short( "general cloth","麻衫");
	set_long(
		"This is a suit of cloth \n",
		"这是一件非常非常普通的衣服，在路上随便都看的到．\n"
		
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "armor_class", 12 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 20, "gold" }) );
}
