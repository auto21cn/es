// OpiumPoppy.c		罂粟
//
//			Lilia

#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("Opium poppy", "罂粟");
    add("id", ({"opium", "poppy"}));
    set_short("罂粟");
    set_long("这朵花就是传说中的罂粟花，是提炼毒品的原料。\n");
    set("ident", "OPIUM");
    set("unit", "朵");
    set("weight", 4);
    set("no_sale", 1);
}

