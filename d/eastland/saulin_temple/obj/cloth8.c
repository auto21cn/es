#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "short cloth", "破短挂" );
	add("id",({"cloth"}) ); 
          set_short( "破短挂" );
	set_long(
"这是一件一般游方和尚穿的衣服，谓之短挂，它有点破了。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "armor_class", 10 );
        set("material","cloth");
	set( "defense_bonus", 2 );
	set( "weight", 50 );
	set( "value", ({ 290, "silver" }) );
}
