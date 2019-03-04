#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "dragonscale sword","龙鳞之剑" );
        add( "id",({ "dragonscale","sword" }) );
        set_short( "dragonscale sword","龙鳞之剑" );
        set_long(@AAA
这是一把用龙的鳞片打造的长剑，隐含者无比的威力
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 27 );
//        set( "bleeding",17 );
        set( "type", "longblade" );
        set( "min_damage", 12 );
        set( "max_damage", 28 );
        set( "weight", 150 );
        set( "value", ({ 930, "silver" }) );
}