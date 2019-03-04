#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "copper longsword","精铜长刃");
        add( "id",({ "sword","longsword" }) );
        set_short( "精铜长刃");
        set_long(
@CLONG
    这是把用高级纯铜所打造的长刀，刀锋锐利，而刀柄用细长的布缠
    /住/，只有高级的黑暗精灵武士能拥有。    
CLONG
                );
        set( "unit", "把" );
        set( "weapon_class", 20 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 32 );
        set( "weight", 110 );
        set( "value", ({ 700, "silver" }) );
}
