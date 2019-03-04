#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("armband of gun-in", "观音臂环");
        add( "id", ({"armband", }) );
        set_short("观音臂环");
        set_long(@C_LONG
臂环一般是头陀使用的防具, 现在一些僧侣也使用臂环以增加防御能力了。
观音臂环相传是观音大士赐给座下天将的信物, 是一种荣誉和神圣的象徵。
C_LONG
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "material","leather" );
        set( "weight", 38 );
        set( "value", ({ 950, "silver" }) );
}
