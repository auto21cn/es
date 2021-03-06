#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("speed pill", "逍遥游" );
	add( "id", ({"pill"}) );
	set_short("逍遥游");
	set_long(
		"这是由刑大娘研发出的解药,专门解除各种麻痹的症状。\n"
		"如果你觉得肌肉僵硬,吃(eat)下它应有不错的效果!\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
	set( "medication", 50 );
}

void eat(object player)
{
    int stat;
    
	if( !player->query("conditions/slow") ) return;
	tell_object( player, can_read_chinese(player)?
		"你觉得肌肉不再僵硬了！\n": "You recover from poison!\n" );
	stat = (int) player->query("slow");
	player->modify_stat("dex",stat);	
	"/std/conditions/slow"->remove_effect(player);
}
