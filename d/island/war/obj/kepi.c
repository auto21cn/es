#include <mudlib.h>

inherit ARMOR;
void create()
{
        set_name( "Kepi","军帽" );
        add( "id",({ "kepi" }) );
        set_short( "军帽" );
	set_long( @LONG
	一顶平凡的军帽。
LONG
		);
        set( "unit","顶" );
        set( "type","head" );
        set( "material","cloth" );
        set( "armor_class",4 );
        set( "defense_bonus",2 );
	set( "weight",30 );
	set( "value",({ 320,"silver" }) );
}

