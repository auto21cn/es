inherit ARMOR;
void create()
{
     set_name( "fighter's plate","战士□铠甲" );
     add( "id",({ "plate","cloth" }) );
     set_short( "战士□铠甲" );
     set_long(@C_LONG
一件由「羽民族大首领  羽后」以天然矿石特制而成的铠甲，上面再加以防雷电咒
语，并在其内侧缝有丝质布料，穿戴起来非常舒适。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",27 );
     set( "defense_bonus",4 );
     set( "value",({ 1220,"silver" }) );
}