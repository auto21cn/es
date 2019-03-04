#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white du-do", "白肚兜" );
	add( "id", ({ "du-do","do" }) );
	set_short( "白肚兜");
	set_long( 
@C_LONG
这是一件白色的肚兜，上面有个大大的金字--「福」。虽然穿起来可能有点好笑，但
是却能提供相当好的保护。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 3 );
	set( "special_defense" ,
	      ([ "divine": 10,"evil":-5 ]) );
	set( "value", ({ 1200, "silver" }) );
}
