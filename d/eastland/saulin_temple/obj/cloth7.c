#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "short cloth", "短挂" );
	add("id",({"cloth"}) ); 
          set_short( "短挂" );
	set_long(
"这是一件一般游方和尚穿的衣服,谓之短挂。\n"
	);
	set( "unit", "件" );
        set("material","cloth");
	set( "type", "body" );
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set( "weight", 70 );
	set( "value", ({ 470, "silver" }) );
}
