#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("orange","柳丁");
	add( "id" , ({ "orange" }) );
	set_short("柳丁");
	set_long(@AAA
	一个新鲜的柳丁，由於老板的坚持你必须当场吃掉它
AAA
	);
   	set("unit","颗");
   	set("weight", 2);
   	set("value",({ 15, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if (owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"你吃下一颗汁多甘甜柳丁，感觉很满足。\n");
		tell_room( environment(owner), 
			owner->query("c_name")+"吃下一颗柳丁看起来好像"
			"很满足的样子\n", owner
		);
		owner->receive_healing( 5+random(5) );
	}
	remove();
}
