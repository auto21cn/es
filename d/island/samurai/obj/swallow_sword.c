
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Swallow Sword", "飞燕之剑" );
        add( "id",({ "swallow","sword" }) );
        set_short( "Swallow Sword", "飞燕之剑" );
        set_long(@AAA
这一神崎梦想流事剑士 橘右京 的配剑，据说右京曾用此剑
斩落空中的飞燕，故此剑有此名！
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 37 );
        set( "weight", 130 );
        set( "value", ({ 1720, "silver" }) );
}
