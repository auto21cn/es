
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "dragonlight sword","名刀龙光");
        add( "id",({ "dragonlight","sword" }) );
        set_short( "dragonlight sword","名刀龙光" );
        set_long(@AAA
这是一把有名的宝刀″龙光″，是武士团中的佼佼者约克的武器
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 30 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 32 );
        set( "weight", 170 );
        set( "value", ({ 1030, "silver" }) );
}



