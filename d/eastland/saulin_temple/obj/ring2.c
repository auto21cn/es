#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("king-kong ring","金刚指环");
        add("id",({"ring"}) );
	set_short("金刚指环");
	set_long(
"这是由金刚界--东方金刚部第二金刚王所使用过的指环,具有非凡的防御力\n"
);
	set( "unit", "个" );
	set( "weight", 10 );
	set("material","element");
	set( "type", "finger" );
	set("armor_class",0);
	set( "defense_bonus", 8 );
	set( "value", ({ 250, "gold" }) );
}
