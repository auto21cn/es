#include <mudlib.h>
inherit WEAPON;
void create()
{
        set_name("king lance","霸王枪");
	add ("id",({ "lance"}) );
        set_short("霸王枪");
	set_long(@C_LONG
霸王枪是「巫罗王」惯用的一把武器，是天帝因功赏赐给他的，对他而言，爱逾性
命。近来战祸不起，「巫罗王」已经很少使用这把武器了，但它本身的威力还是存
在的。
C_LONG
	);
	set( "unit", "把" );
        set( "nosecond", 1 );
        setup_weapon("jousting", 35,10,30);
	set("no_sale",1);
	set( "weight", 250 );
	set( "value", ({ 20000, "silver" }) );
}

