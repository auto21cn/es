inherit ARMOR;
void create()
{
     set_name( "white cloth","白色官服" );
     add( "id",({ "cloth" }) );
     set_short( "白色官服" );
     set_long(@C_LONG
这是一件「巫咸国」里寻常文官所穿的衣服，一袭纯白，造形并不花俏。 
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "armor_class",26);
     set( "defense_bonus",5 );
     set( "value",({ 1000,"silver" }) );
}
