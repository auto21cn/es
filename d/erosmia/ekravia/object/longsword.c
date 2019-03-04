#include "../ekravia.h"

inherit WEAPON;

void create()
{
        set_name( "longsword", "长剑" );
        add( "id",({ "sword", "longsword" }) );
        set_short( "长剑" );
        set_long( @CLONG
一把普通的长剑, 几乎每个地方的铁匠都会制造的武器。
CLONG
        );
        set( "unit", "把");
        set( "weapon_class", 25 );
        set( "type", "longblade" );
        set( "min_damage", 12 );
        set( "max_damage", 24 );
        set( "nosecond",1);
        set( "weight", 160 );
        set( "value", ({ 600, "silver" }) );
}
