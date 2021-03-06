#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("spirit pill","醒脑丸" );
	add( "id", ({"pill"}) );
	set_short("醒脑丸");
	set_long(
		"这是一份行医者所调配的醒脑丸，吃(eat)下它可以解除混乱的\n"
		"状态。\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 10 );
	set( "value", ({ 30, "silver" }) );
        set( "medication", 50 );
}

void eat(object player)
{
	if( !player->query("conditions/confused") ) return;
//      tell_object( player,
//             "你所觉的脑子清醒多了 !\n");
	CONFUSED->remove_effect(player);
}
