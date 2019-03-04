#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Dragon ring","龙戒" );
     add( "id",({ "ring" }) );
     set_short( "龙戒" );
     set_long(@C_LONG
一只水晶制成的小巧戒指，戒指上雕刻著一个龙头。
C_LONG
     );
     set( "weight",20 );
     set( "unit", "只");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
}
