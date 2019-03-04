#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create()
{
	set_name("wheet wine","大麴酒");
	add( "id" , ({ "wine" }) );
	set_short("大麴酒");
	set_long("打开瓶子，你看到成透明颜色的酒，闻来极为香醇....!!\n");
   	set("unit","瓶");
   	set("weight", 10);
   	set("value",({ 10, "gold" }) );
}

int quaff_potion(string arg)
{
	if(!arg||( arg != "wheet wine" && arg!= "wine") ) return 0;
	write( "你一口灌下整瓶酒，只觉的整个人轻飘飘的。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"一口灌下一整瓶大麴酒，然後"
		"便不断的喃喃自语，好像在说些什麽秘密!!\n",this_player()
	);
	remove();
	return 1;
}
