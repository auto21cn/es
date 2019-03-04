#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("vodka","伏特加");
	add( "id" , ({ "vodka","wine" }) );
	set_short( "伏特加" );
	set_long("好刺鼻的酒...一定很烈!!\n");
   	set("unit","瓶");
   	set("weight", 10);
   	set("value",({30, "silver"}) );
}

int quaff_potion(string arg)
{

	if( ! id(arg) ) return 0;
	write( 
		"你喝下一瓶伏特加，感到整个人燥热起来。\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"一口喝下一瓶伏特加，然後马上满脸通红的傻笑起来!!\n",
		this_player() );

	remove();
	return 1;

}
	
