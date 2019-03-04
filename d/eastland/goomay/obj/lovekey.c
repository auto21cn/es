#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Necklace of love","情关意锁");
        add("id",({"necklace"}) );
         set_short( "Necklace of love","情关意锁");
	set_long(
"This is a magic necklace , it is growing and you feel you got a strong mind .\n",
"这是一条系著一把金色钥匙的项□，这把奇异的钥匙散发出一种憾人心弦\n"+
"的光芒，看到了它，你觉得在也不□徨了。\n"
	);
	set( "no_sale",1);
	set( "unit", "条" );
	set( "weight", 20 );
        set("material","light_metal");
	set( "type", "misc" );
	set( "armor_class", 0 );
        set( "defense_bonus", 6 );
	set( "value", ({ 200, "gold" }) );
        set("special_defense",(["mental":30, ]));
        set("extra_stats",(["con":-1 ]));

}
