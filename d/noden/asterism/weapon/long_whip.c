
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("long whip","长鞭");
        add ("id",({ "whip" }) );
        set_short("长鞭");
        set_long(
            "这是一条很长的鞭子。仔细一看, 上面什麽花纹都没有。\n"
        );
        set( "unit", "条");
        set( "weapon_class", 20 );
        set( "type", "whip" );
        set( "min_damage", 17);
        set( "max_damage", 19 );
        set( "weight", 110 );
        set( "value", ({ 840, "silver" }) );
}

