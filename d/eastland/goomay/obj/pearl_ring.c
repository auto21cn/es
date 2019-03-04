#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "pearl ring", "珍珠戒指" );
	add( "id", ({ "ring" }) );
	set_short( "a pearl ring", "珍珠戒指" );
	set_long(
		"You see a beautiful pearl ring with a big pearl on it.\n",
		"这是一个很漂亮的珍珠戒指，上面镶著一颗大大的珍珠。\n"
	);
	set( "type", "finger" );
        set("material","stone");
	set( "defense_bonus", 5 );
	set( "weight", 10 );
	set( "value", ({ 400, "silver" }) );
	
}
