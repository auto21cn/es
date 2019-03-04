#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Diamond Ring","维纳斯白钻" );
        add( "id", ({ "ring","diamond ring" }) );
	set_short( "维纳斯白钻" );
        set_long(
                "这是希腊月神维纳斯的戒指，其上所镶的白钻是人间绝无仅有的。\n"
        );
        set( "unit", "只" );
	set("material","adv");
        set( "type", "finger" );
        set( "armor_class",0 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 7000, "silver" }) );
}
