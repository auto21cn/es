#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("paradise dagger", "仙鹤神针");
        add ("id",({ "dagger",}) );
        set_short("仙鹤神针");
        set_long(
"传说中天上仙人所用的武器，形状类似匕首。你可以看到它周围隐约闪耀著
蓝光，相当耀眼。\n"
        );
        set( "unit", "柄" );
        set( "weapon_class", 40 );
        set( "type", "dagger" );
        set( "min_damage", 25 );
        set( "max_damage", 35 );
        set( "weight", 50 );
        set( "no_sale", 1);
        set( "value", ({ 2600, "silver" }) );
        set( "bleeding", 8 );
}
