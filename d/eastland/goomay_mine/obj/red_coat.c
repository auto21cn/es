#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("red coat","红云衫");
        add("id",({"cloth","red"}) );
        set_short("红云衫");
	set_long(@AA
一件火红的衣裳，没有什麽特别的地方，上面的钮扣早已坏的坏掉的掉了，
还染上了不少的酒渍，不过每当老酒鬼喝醉的时候，就会对著这件衣服默默
地掉下几滴泪水，想必它又是一个故事的见证．
AA
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 20 );
	set( "defense_bonus", 5 );
	set( "value", ({ 250, "gold" }) );
}
