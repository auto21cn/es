// casablanca.c

#include "../lilia.h"

inherit OBJECT;

void create()
{
    set_name("casablanca", "香水百合");
    add("id", ({"casablanca", "lily", "flower"}));
    set_short("香水百合");
    set_long("香水百合，花中的女王，花语是伟大的爱。\n");
    set("unit", "朵");
    set("no_sale", 1);
}
