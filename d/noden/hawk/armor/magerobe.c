#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Spirit robe","灵力之袍" );
        add( "id", ({ "robe","cloth" }) );
        set_short( "灵力之袍" );
        set_long(
                "一件看起来破破烂烂的袍子，但却有著相当不错的防护力。\n"
        );
        set( "unit", "领" );
        set("material","cloth");
        set( "type", "body" );
        set( "armor_class", 26 );
        set( "defense_bonus", 4 );
        set( "weight", 90 );
        set( "value", ({ 410, "silver" }) );
}
