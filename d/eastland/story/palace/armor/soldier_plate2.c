#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "silver plate","白银铠甲" );
     add( "id",({ "plate" }) );
     set_short( "白银铠甲" );
     set_long(@C_LONG
一件白银制成的铠甲，造型别致，穿起来英挺极了。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","heavy_metal" );
     set( "armor_class",34 );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
}
