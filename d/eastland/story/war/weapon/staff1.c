#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "wind wand", "魔风杖" );
    add( "id", ({ "wand" }) );
    set_short( "魔风杖" );
    set_long(@LONG
一把白银制成的武器，上刻锦绣云朵，前端分开两叉。
LONG
    );
    set( "unit", "把" );
    setup_weapon("wand",30,10,20 );
    set( "power_on", 1);
    set( "weight", 50 );
    set( "value", ({ 2000, "silver" }) );
    set( "hit_func", "wand_hit" );
    set( "charge_left", 10 );
    set( "max_charge", 10 );
    set( "special_damage_type", "evil" );
    set( "special_damage", 30 );
    set( "special_c_msg", " 发出黑色暴风! ");
}
