inherit ARMOR;
void create()
{
     set_name( "fighter's leggings","战士□胫甲" );
     add( "id",({ "leggings" }) );
     set_short( "战士□胫甲" );
     set_long(@C_LONG
一件由「羽民族大首族  羽后」以天然矿石特制而成的胫甲，上面再加以防雷电咒
语，同时在内侧缝有丝质布料，穿戴起来非常舒适。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "legs" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",3 );
     set( "value",({ 720,"silver" }) );
     set("special_defense",
         (["electric":5]) );
}