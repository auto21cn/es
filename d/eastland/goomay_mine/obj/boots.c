#include "../zeus.h"

inherit ARMOR;

void create()
{
        set_name("comfortable boots", "快意薄靴");
        add( "id", ({ "boots","boot" }) );
        set_short("快意薄靴");
        set_long(@AA
这是一双由软皮革所制成的薄底快靴，穿起来又软又舒服，鞋类中的上品．
AA
);
        set( "unit", "双");
        set( "type", "feet" );
        set("material","leather");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "weight", 40 );
        set( "value", ({ 600, "silver" }) );
        }