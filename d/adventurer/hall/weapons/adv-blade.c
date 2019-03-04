
#include "mudlib.h"
inherit WEAPON;

void create()
{
        set_name("hash blade", "开山刀");
        add ("id",({ "blade" }) );
        set_short("开山刀");
        set_long(
            "这是一把厚重的刀，冒险者利用它在山林中披荆斩棘。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 28 );
        set( "type", "longblade" );
        set( "min_damage", 15);
        set( "max_damage", 25 );
        set( "wield_func","wield_blade" );
        set( "unwield_func","unwield_blade" );
        set( "weight", 160 );
        set( "value", ({ 2500, "silver" }) );
}
void unwield_blade()
{
        object holder;
                
        if( !holder=environment(this_object()) ) return;
        set( "min_damage",15 );
        set( "max_damage",25 );
        set( "prevent_drop",0 );
        return ;
 }                                                                                                                                                                 
 void wield_blade()
{
    object holder;
    if( !holder=environment(this_object()) ) return;
    if ((string)this_player()->query("class") != "adventurer" ) return ;
    set( "min_damage",23 );
    set( "max_damage",35 );
    set( "prevent_drop",1 );
    return;
}    