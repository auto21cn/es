#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's skirt","蚩尤绑腿");
        add("id",({"skirt"}) );
        set_short("蚩尤绑腿");
	set_long(@C_LONG
一件用布料缝制而成的护具，上面沾满了许多血渍，还有许多五条朱线做一起的符
号，那是蚩尤用来记算每杀五个人的辨别。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",60 );
	set( "type", "legs" );
        set("material","cloth");
	set( "defense_bonus", 1 );
	set( "value", ({ 1000, "silver" }) );
}
