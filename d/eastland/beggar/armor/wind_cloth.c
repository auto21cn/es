#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind cloth","束云白袍");
        add("id",({"cloth"}) );
        set_short("束云白袍");
	set_long(@C_LONG
束云白袍是由震八方乔峰死去的妻子用天然蚕丝编织而成的,因上面绣有一大片浮云而
命名的。因为是丝制品,所以对於防火而言总有那麽一点缺陷。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 32 );
	set( "defense_bonus",3 );
	set("special_defense",
	     (["fire":-20,"cold":10]) );
	set( "value", ({ 4800, "silver" }) );
	set("no_sale",1);
}
