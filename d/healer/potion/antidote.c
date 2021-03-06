#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("antidote pill", "解毒丸" );
	add( "id", ({"pill"}) );
	set_short("an antidote pill", "解毒丸");
	set_long(
		"You see an antidote mixture of healers. You can eat it to\n"
		"cure poison.\n",
		"这是一份行医者所调配的解毒丸，吃(eat)下它可以解除一般毒蛇、毒\n"
		"虫的毒性，对於比较重的毒则有减短中毒时间的效果。\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
	set( "medication", 50 );
}

void eat(object player)
{
	mixed *cond_data;
	if( !player->query("conditions/simple_poison") ) return;

	cond_data = player->query("conditions/simple_poison");
	if (!sizeof(cond_data) == 3) return;

	if (cond_data[1] >= 6)
	{
	    cond_data[1] /= 2;
	    player->set("conditions/simple_poison", cond_data);
	    tell_object(player, "你觉得好一点了 ....\n");
	}
	else
	{
	    tell_object( player, "你所中的毒解除了！\n" );
	SIMPLE_POISON->remove_effect(player);
	}
}
