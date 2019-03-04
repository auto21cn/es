#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Wind Dagger","风刃匕首");
    add("id",({ "dagger" }) );
    set_short("风刃匕首");
    set_long( @C_LONG
这是一把精心设计的匕首，锋利的刀刃泛著闪亮的青光，彷佛在渴望著要吸食生血。
C_LONG
            );
    set("unit","把");
    set("weapon_class",25);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",22);
    set("weight",50);
    set("value", ({400,"silver"}) );
}
