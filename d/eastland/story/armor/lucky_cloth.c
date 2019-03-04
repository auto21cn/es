#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "red cloth","大红衣服" );
     add( "id",({ "cloth" }) );
     set_short( "大红衣服" );
     set_long(@C_LONG
一件赤红色的宽大衣服，两个□肩高高的，穿起来蛮有威严。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",1 );
     set( "value",({ 400,"silver" }) );
     set("special_defense",
         (["electric":50]) );
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