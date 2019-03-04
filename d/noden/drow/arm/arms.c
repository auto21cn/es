#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("snake armbands", "蛇护臂");
   add( "id", ({ "armbands" }) );
        set_short( "蛇护臂" );
        set_long(
@C_LONG
这是一个由蛇皮缠卷成的护臂，边缘还用铜片交织紧密地结合。
C_LONG
        );
        set( "unit", "对");
        set( "type", "arms" );
        set( "material", "leather" );
   set( "armor_class", 3 );
   set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "poison": 18, "cold": -5 ]) );
        set( "weight", 32 );
        set( "value", ({ 110, "gold" }) );
        set( "no_sale", 1);
}
