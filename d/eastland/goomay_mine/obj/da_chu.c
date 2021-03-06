#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create()
{
	set_name("da chu","陈年大麴");
	add("id" ,({"wine","chu"}) );
	set_short( "陈年大麴");
	set_long(@LONG
陈年大麴就是俗称的：二锅头，因为要经过两次发酵，撷取高粱的精华，酒精
浓度也特别高，在百分之六十以上，一般人是浓烈而难以入口的
LONG
);
   	set("unit","壶");
   	set("weight", 50);
   	set("value",({100, "silver"}) );
}

int quaff_potion(string arg)
{
	if( !arg || arg != "da chu" ) return 0;
	write( "你喝下一壶二锅头。感到全身开始发烫，但是有一种想吐的感觉。\n"
	       "你开始到处抓兔子！\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下一壶二锅头，然後"
		"开始在地上到处乱爬，不知道想做什麽？\n" , this_player()
	);
	remove();
	return 1;
}
