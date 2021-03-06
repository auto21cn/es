#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "god wand", "神禹令" );
    add( "id", ({ "wand" }) );
    set_short( "神禹令" );
    set_long(@LONG
一面画著许多符□的牌子，整块黑溜溜的，有点像黑炭。
LONG
    );
    set( "unit", "面" );
    set( "type", "wand" );
    set( "weapon_class", 23 );
    set( "min_damage", 7 );
    set( "max_damage", 22 );
    set( "power_on", 1);
    set( "weight", 40 );
    set( "value", ({ 1500, "silver" }) );
    set( "hit_func", "wand_hit" );
    set( "charge_left", 10 );
    set( "max_charge", 10 );
    set( "special_damage_type", "evil" );
    set( "special_damage", 10 );
    set( "special_c_msg", set_color(" 暴出一团紫色的浓雾! ","HIM") );
}
