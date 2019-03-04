inherit ARMOR;
void create()
{
     set_name( "The Archmaster's robe","护国师□袍" );
     add( "id",({ "robe" }) );
     set_short( "护国师□袍" );
     set_long(@C_LONG
一件绣著白云图案的丝制袍子。在这件袍子上还有著天神的祝福，在白云里不时有
五色祥光出现。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "armor_class",30);
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
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