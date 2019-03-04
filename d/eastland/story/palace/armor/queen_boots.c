#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";

void create()
{
     set_name( "Queen's shoes","绣丝彩靴" );
     add( "id",({ "shoes","boots" }) );
     set_short( "绣丝彩靴" );
     set_long(@C_LONG
一双用丝料缝制而成的鞋子，再染以七彩颜色，非常好看。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "双");
     set( "type", "feet" );
     set( "material","cloth" );
     set( "the_one",1);
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "value",({ 1000,"silver" }) );
     set( "special_defense",(["evil":20]));
}
