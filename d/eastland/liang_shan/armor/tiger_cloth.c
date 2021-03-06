#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("tiger fur cloth","虎皮套体");
    add("id",({"fur","cloth"}) );
    set_short( "tiger fur cloth","虎皮套体");
	set_long(
		"This is a cloth made of fur of tiger\n",
		"这是用虎皮制成的衣物，剪裁非常的朴实无华，略能敝体．\n"
	);
	set( "unit", "件" );
	set( "weight", 160 );
	set( "type", "body" );
	set( "armor_class", 24 );
        set("material","leather");
	set( "defense_bonus", 3 );
	set( "value", ({ 75, "gold" }) );
        set( "special_defense",(["none":8]));
}
