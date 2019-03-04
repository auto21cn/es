#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("damo pallium","达摩架裟");
    add("id",({"cloth","pallium"}) );
    set_short("达摩架裟");
	set_long(@C_LONG
这是一件看来很破旧的架裟,相传是当年达摩老祖所留下来的,只有
级位相当高的和尚有资格穿著,相传它附有达摩老祖的佛法,能帮你
躲过魔孽。
C_LONG
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "armor_class", 34 );
        set("material","monk");
	set( "defense_bonus", 6 );
	set( "value", ({ 200, "gold" }) );
}
