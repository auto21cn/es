#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding lace", "白色新娘头纱");
        add( "id", ({ "lace" }) );
        set_short( "a wedding lace", "白色新娘头纱");
        set_long(
                "A white wedding lace .\n",
		 "这是用纯白的蕾丝做成的美丽头纱，上面还缀著几朵红色的玫瑰。\n"
        );
        set("unit","顶");
        set("material","cloth");
        set( "type", "head" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "weight", 10 );
	set( "no_sale",1);
        set( "value", ({ 1800, "silver" }) );
}



