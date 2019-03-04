#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "silver shield","白银盾牌" );
     add( "id",({ "shield" }) );
     set_short( "白银盾牌" );
     set_long(@C_LONG
一件白银制成的盾牌，不时在盾面闪耀著银光，刺眼极了。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "shield" );
     set( "material","heavy_metal" );
     set( "armor_class",7 );
     set( "defense_bonus",4 );
     set( "value",({ 3500,"silver" }) );
}
