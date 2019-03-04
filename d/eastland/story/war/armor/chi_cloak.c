#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's cloth","蚩尤战袍");
        add("id",({"cloth"}) );
        set_short("蚩尤战袍");
	set_long(@C_LONG
一件用布料缝制而成的护具，上面沾满了许多血渍，前面还绣有一个红色的大骷髅
头。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set( "material","cloth");
	set( "armor_class",20);
	set( "defense_bonus", 4 );
	set( "value", ({ 1000, "silver" }) );
}
