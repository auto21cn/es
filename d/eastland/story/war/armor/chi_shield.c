#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's shield","地狱之盾");
        add("id",({"shield"}) );
        set_short("地狱之盾");
	set_long(@C_LONG
一件用布料缝制而成的盾牌，上面沾满了许多血渍和刀斫的痕迹。
C_LONG	         );
	set( "unit", "面" );
	set( "weight",70 );
	set( "type", "shield" );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}
