#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("wire jade", "绳文玉佩");
        add( "id", ({ "jade" }) );
        set_short("绳文玉佩");
        set_long(
                "这是一块有绳文的古代玉佩....\n"
        );
        set( "unit", "个");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0);
        set( "defense_bonus", 7 );
        set( "special_defense",
             ([ "evil":6, "none":-6 ]) );
        set( "weight", 30 );
        set( "value", ({ 1470, "silver" }) );
}
