#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        set_name( "apple", "苹果" );
        add( "id", ({ "apple" }) );
        set_short( "苹果" );
        set_long(@C_LONG
这是一个红苹果，看起来十分新鲜美味，吃(eat)了它以後想必
能提振一些精神吧 !!
C_LONG
		);
   		set("unit","颗");
   		set("weight", 10);
   		set("value",({40, "silver"}) );
}

int eat_food(string arg)
{
	if( !arg || arg != "apple") return 0;
	write( "你狼吞虎□地啃掉了一颗苹果，觉得齿颊留香...:)\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"三两下就啃掉了一颗苹果，你都看呆了...\n"
		, this_player()
	);
	this_player()->receive_healing(5);
	remove();
	return 1;
}
