#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("green cloth","翠烟罗");
        add("id",({"cloth","green"}) );
        set_short("green cloth","翠烟罗");
	set_long(
"This is a suit of cloth made of silk meterial.\n",
"『孤灯寒照雨，深竹暗浮烟，故人江海别，几度隔山川。』 \n"  
"这是用江南的翠蚕丝和寒烟山庄的寒烟绸编织而成的衣裳。 \n"   
"是『江南一剑』江羽送给灵儿的定情之物，然流水有情，落花无意... \n"
	);
	set( "unit", "件" );
	set( "weight", 135 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 20 );
	set( "defense_bonus", 10 );
	set( "value", ({ 250, "gold" }) );
	set("no_sale",1);
}
