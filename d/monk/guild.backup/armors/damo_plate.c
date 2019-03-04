#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("damo plate","破魔圣甲");
    add("id",({"plate","damo"}) );
    set_short( "damo plate","破魔圣甲");
	set_long(
"This is a suit of plate, and it is worn by damo.\n",
"这是一件看来很破旧的战甲, 相传是当年帝释天和阿修罗战斗时所留下来的, 它隐隐\n"
"包围著一阵光晕, 散发出一股神圣的气息... \n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 360 );
	set( "type", "body" );
    set( "material","heavy_metal");
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "value", ({ 200, "gold" }) );
}
