#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "White skirt","白练战裙" );
     add( "id",({ "skirt" }) );
     set_short( "白练战裙" );
     set_long(@C_LONG
一件白色的围裙，不论男女皆可以穿戴。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "legs" );
     set( "material","cloth" );
     set( "armor_class",1 );
     set( "defense_bonus",2 );
     set( "value",({ 1000,"silver" }) );
}
