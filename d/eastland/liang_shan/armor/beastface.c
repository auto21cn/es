#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("beast-face", "兽面掩心");
        add( "id", ({ "face" }) );
        set_short("兽面掩心");
        set_long(
                "算是一种护心镜，但防御力更佳，是梁山泊马军五虎将的信物．\n"
        );
        set( "unit", "面");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0);
        set( "defense_bonus", 8 );
        set( "special_defense",
             ([ "poison":-5,"none":4 ]) );
        set( "weight", 20 );
        set( "value", ({ 470, "silver" }) );
}
