inherit ARMOR;
void create()
{
     set_name( "white belt","白练腰带" );
     add( "id",({ "belt" }) );
     set_short( "白练腰带" );
     set_long(@C_LONG
一件纯白色的腰带，为「巫咸国」里所文官惯穿。这腰带是用天然布料做成的，触
感还不错。
C_LONG
     );
     set( "unit","件" );
     set( "weight",60 );
     set( "type","legs" );
     set( "material","cloth" );
     set( "armor_class",6 );
     set( "defense_bonus",5 );
     set( "value",({ 720,"silver" }) );
}