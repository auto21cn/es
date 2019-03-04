#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("jade cloth","金缕\玉\衣");
    add("id",({"jade","cloth"}) );
    set_short( "金缕\玉\衣");
	set_long(
		"这是一件金缕\玉\衣，玉在东方人的心中可以避邪驱魔，带来好运．\n"
		"这件衣服完全由玉制成，穿上它会有不可思议的效果．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "armor_class", 31 );
        set("material","element");
	set( "defense_bonus", 10 );
	set( "value", ({ 290, "gold" }) );
        set( "special_defense",(["evil":10,"poison":8,"devine":-10,"acid":6,"none":7]));
        set( "extra_stats",(["dex":-3,"kar":1,"str":-1]));
                                    
}
