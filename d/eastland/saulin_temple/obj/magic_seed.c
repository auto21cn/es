#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "Relic of Damo", "达摩舍利子" );
	add( "id", ({ "relic" }) );
	set_short( "达摩舍利子" );
	set_long(@C_LONG
这虽然只是颗小小的舍利子，但上面宝光流动，显得十分不平凡，据说
它可以抵御三昧真火。要使用舍利子，用 throw <someone>。
C_LONG
	        );
	set( "unit", "颗" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_throw", "throw" );
}

int do_throw(string arg)
{
	object obj;

	if( !arg )
		return notify_fail("要用舍利子丢谁？\n");
	if( !( obj = present(arg, environment(this_player())) ) )
		return notify_fail( "这里没这个人。\n");
	if( undefinedp(obj->query("zapped")) ) {
		write( 
			"你拿出舍利子丢向"+obj->query("c_short")+"，不过对方似乎不受影响。\n"
		);
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"拿出一颗小小的东西丢向"+obj->query("c_short")+"。\n"
			, this_player()
		);
	} else {
		write( 
			"你拿出舍利子丢向"+obj->query("c_short")+".... \n" 
		);
		tell_room( environment(this_player()), 
			 this_player()->query("c_name")+
			"拿出一颗舍利子丢向"+obj->query("c_short")+"。\n"
			, this_player()
		);
		write( "你的舍利子直直的向"+obj->query("c_short")+"的面门打去。\n");
		obj->zapped();
		remove();
	}
	return 1;
}
