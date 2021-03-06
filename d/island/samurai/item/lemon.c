#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("lemon","柠檬");
	add( "id" , ({ "柠檬" }) );
	set_short("柠檬");
	set_long(@AAA
	一个新鲜的柠檬，由於老板的坚持你必须当场吃掉它
AAA
	);
   	set("unit","颗");
   	set("weight", 2);
   	set("value",({ 50, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if (owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"你吃下一颗柠檬，实在有够酸，但你依然觉得很舒服。\n");
		tell_room( environment(owner), 
			owner->query("c_name")+"吃下一颗柠檬，整个脸因为太酸而"
			"扭曲了．．．．\n", owner
		);
		owner->receive_healing( 5+random(10) );
	}
	remove();
}
