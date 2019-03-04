#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("small golden ring","小金圈儿");
        add("id",({"ring"}) );
         set_short( "a small golden ring","小金圈儿");
	set_long(
		 "This is a small ring. \n",
		 "一个小小的金戒指，上面刻了一个小小的『唐』字。\n"
		 );
	set( "unit", "只" );
        set("material","light_metal");
	set( "weight", 10 );
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 2 );
	set( "value", ({  12, "gold" }) );
}
