#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	set_name("blind plaster", "明目膏" );
	add( "id", ({"plaster"}) );
	set_short("明目膏");
	set_long(
		"这是用来治疗轻微眼睛伤害的药膏, 把他涂(apply)在眼睛上可以改善\n"
		"失明的状况, 如果伤的太重, 还是要靠手术医疗。\n"
	);
	set( "can_apply", 1 );
	set( "unit", "份" );
	set( "weight", 20 );
	set( "value", ({ 100, "silver" }) );
}

int apply(object player)
{
	int degree;
	if( !(degree=player->query("blind")) ) return 0;
	if( degree > 5) {
	  tell_object(player, "你的眼伤太重, 敷药已经没用了, 找医生动手术吧。\n");
	  return 1;
	}  
	degree--;
	if (degree<1) { 
	  player->delete("blind");
	  tell_object(player, "你的眼睛又能看到东西了。\n");
	}  
	else {
	  player->set("blind",degree);
	  tell_object(player,"你的眼睛好了一些, 但仍看不清楚。\n");
	}  
	return 1;
}
