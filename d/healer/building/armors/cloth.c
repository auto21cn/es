#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Doctor cloth","医师诊袍");
        add("id",({"cloth"}) );
        set_short("医师诊袍");
	set_long("这是行医者最喜欢穿的衣服, 除了能够保暖之外, 它\n"
	         "也是行医者身份的象徵。\n");
	set( "unit", "件" );
	set( "weight", 80 );
	set( "type", "body" );
        set("material","healer");
	set( "armor_class", 17 );
	set( "defense_bonus", 5 );
	set( "value", ({ 1800, "silver" }) );
	set("no_sale",1);
}
