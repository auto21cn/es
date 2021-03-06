#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("god armbands", "观音臂环");
        add( "id", ({"armband","armbands" }) );
        set_short("a god armbands", "观音臂环");
        set_long(
        "An armband used by great monk.\n",
		"臂环一般是头陀使用的防具, 现在一些僧侣也使用臂环以增加防御能力了。\n"
		"观音臂环相传是观音大士赐给座下天将的信物, 是一种荣誉和神圣的象徵。\n"
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "armor_class", 5 );
        set( "defense_bonus", 5 );
        set( "material","leather" );
        set( "weight", 38 );
        set( "no_sale", 1);
        set( "value", ({ 950, "silver" }) );
}
