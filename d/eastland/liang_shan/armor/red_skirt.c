#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("red skirt", "鲜红生绢裙");
        add( "id", ({ "skirt" }) );
        set_short("red skirt", "鲜红生绢裙");
        set_long(
                "a short skirt made of silk .\n",
                "用生丝染色制成的鲜红色裙子，女孩子穿上他一定很好看．\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":-2, "fire":3 ]) );
                       
        set( "weight", 60 );
        set( "value", ({ 50, "gold" }) );
}
