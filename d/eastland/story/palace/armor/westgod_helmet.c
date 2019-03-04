#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Westgod's helmet","@@query_short" );
     add( "id",({ "helmet", }) );
     set_short( "@@query_short" );
     set_long(@C_LONG
一顶金澄澄的头冠，上面镶有各色珠宝，耀眼生辉。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "顶");
     set( "type", "head" );
     set( "material","heavy_metal" );
     set( "armor_class",8 );
     set( "defense_bonus",3 );
     set( "value",({ 3000,"silver" }) );
     set( "special_defense",(["divine":10]));
}
string query_short()
{
       return set_color("星天冠","HIY") ;
}