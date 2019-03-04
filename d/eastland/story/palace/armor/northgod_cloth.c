#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Crystal plate","水晶铠甲" );
     add( "id",({ "plate" }) );
     set_short( "水晶铠甲" );
     set_long(@C_LONG
一件水晶制成的铠甲，表面却如同镜子一般，没有任何纹路。
C_LONG
     );
     set( "weight",110 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",35 );
     set( "defense_bonus",8 );
     set( "value",({ 4000,"silver" }) );
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
}
int equip_cloth()
{
     this_player()->add_temp("can_pass_spell",1 );
     return 1;
}
int unequip_cloth()
{
     this_player()->add_temp("can_pass_spell",-1);
     return 1;
}