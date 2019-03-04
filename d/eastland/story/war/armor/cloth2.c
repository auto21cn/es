#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wind cloth","风神衣");
        add("id",({"cloth"}) );
        set_short("风神衣");
	set_long(@C_LONG
一件上绣云朵的纯白色衣服，类似用蚕丝编织而成的，看起来有些透明。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}
