#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's helmet","蚩尤战盔");
        add("id",({"helmet"}) );
        set_short("蚩尤战盔");
	set_long(@C_LONG
一件用布料缝制而成的护头，上面插了几根羽毛，有点像印地安那头上穿的东西。
C_LONG	         );
	set( "unit", "顶" );
	set( "weight",60 );
	set( "type", "head" );
        set("material","cloth");
	set( "defense_bonus", 2 );
	set( "value", ({ 1000, "silver" }) );
}
