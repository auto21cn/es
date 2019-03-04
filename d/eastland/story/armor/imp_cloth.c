#include "../story.h";
inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "cloth of God","羽神衣" );
     add( "id",({ "cloth" }) );
     set_short( set_color("羽神衣","HIY") );
     set_long(@C_LONG
这是一件经过神的血洗礼而成的衣服，并经过天神祝福的防具。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "armor_class",22 );
     set("the_one",1);
     set( "defense_bonus",2 );
     set( "value",({ 2300,"silver" }) );
     set("special_defense",
        (["magic":35,"fire":30]) );
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