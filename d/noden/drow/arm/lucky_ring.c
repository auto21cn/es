#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky ring", "幸运戒指");
   add( "id", ({ "ring" }) );
        set_short( "幸运戒指" );
        set_long(
@C_LONG
这是一只可爱而精致的戒指，镶有一颗小小的翡翠，并且雕刻的像
小刀子的标志。
C_LONG
        );
        set( "unit", "只");
        set( "type", "finger" );
        set( "material","thief" );
        set( "extra_stats",([ "pie" : -1 ]) );
   set( "extra_skills", ([ "steal" : 10 ]) );
        set( "defense_bonus", 2 );
        set( "special_defense",
          ([ "cold": 40, "fire" : -50 ]) );
        set( "weight", 7 );
        set( "value", ({ 410, "gold" }) );
        set( "no_sale", 1);
}
