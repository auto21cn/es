#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("apple","苹果");
	add( "id" , ({ "苹果" }) );
	set_short("apple" , "苹果");
	set_long(@AAA
	一个新鲜的苹果，由於老板的坚持你必须当场吃掉它
AAA
	);
   	set("unit","颗");
   	set("weight", 2);
   	set("value",({ 20, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if ( owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"你吃下一颗新鲜苹果，咬起来有够脆，汁又多让你还想再吃一个。\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"吃下一颗苹果看起来好像很愉快的样子\n"
			, owner
		);
		owner->receive_healing( 5+random(5) );
	}
	remove();
}
