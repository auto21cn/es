#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("The Archmaster's ring","护国师□戒");
        add( "id", ({ "ring" }) );
        set_short( "护国师□戒");
        set_long(@C_LONG
一只晶莹剔透不时闪耀著五彩祥云的戒指。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 1 );
        set( "value", ({ 1500, "silver" }) );
        set("special_defense",
             (["magic":30,"divine":-60]) );
}



