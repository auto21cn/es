#include <mudlib.h>
inherit WEAPON;
void create()
{
        set_name("phoenix topknot", "凤头钗");
        add( "id", ({ "topknot" }) );
        set_short("凤头钗");
        set_long(
                "这是刑老爹送给刑老妈的定情之物, 上面有一只很精致的凤凰。\n"
        );
        set("unit","支");
        set( "type", "dagger" );
        set( "weapon_class",35);
        set( "min_damage", 15);
        set( "max_damage",30);
        set( "weight", 30 );
        set( "value", ({ 450, "gold" }) );
}



