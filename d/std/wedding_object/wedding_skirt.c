#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding skirt", "白色新娘曳地长裙");
        add( "id", ({ "skirt" }) );
        set_short( "a wedding skirt", "白色新娘曳地长裙");
        set_long(
                "A white wedding skirt made of white silk.\n",
                "这是一件由天然蚕丝织成的曳地白色新娘长裙。\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "armor_class", 8 );
        set("material","cloth");
        set( "defense_bonus", 2 );
        set( "weight", 70 );
	set("no_sale",1);
        set( "value", ({ 60, "gold" }) );
}
