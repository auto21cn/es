#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Gold-God's shield","曲盾" );
     add( "id",({ "shield" }) );
     set_short( "曲盾" );
     set_long(@C_LONG
一面黄金制成的盾牌，圆圆的，好似一颗大球。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "面");
     set( "type", "shield" );
     set( "material","heavy_metal" );
     set( "armor_class",5 );
     set( "defense_bonus",1 );
     set( "value",({ 1500,"silver" }) );
}
