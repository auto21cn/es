inherit ARMOR;
void create()
{
     set_name( "golden plate","黄金铠甲" );
     add( "id",({ "plate","cloth" }) );
     set_short( "黄金铠甲" );
     set_long(@C_LONG
一件纯金打造的铠甲，金光闪闪相当昂贵。
C_LONG
     );
     set( "weight",250 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","heavy_metal" );
     set( "armor_class",34);
     set( "defense_bonus",5 );
     set( "value",({ 2500,"silver" }) );
}