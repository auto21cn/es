#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
   set_name( "saliva of chocobo", "陆行鸟的口水" );
   add( "id", ({ "saliva", "water" }) );
   set_short( "陆行鸟的口水" );
	set_long(
           "这是陆行鸟的口水, 你可以试试把它喝下去。\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
   set( "unit", "滩" );
	set( "weight", 20 );
	set( "value", ({ 80, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
