#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("xo","ＸＯ");
	add( "id" , ({ "wine","xo" }) );
	set_short( "ＸＯ" );
	set_long( "ＸＯ，还要解释吗？喝下就是了。\n" );
   	set("unit","杯");
   	set("weight", 10);
   	set("value",({30, "silver"}) );
}

int quaff_potion(string arg)
{

	if( ! id(arg) ) return 0;
	write (
		"你喝下一杯ＸＯ。感到头有点晕晕的，但是有一种兴奋的感觉。\n你高兴得唱起歌来...\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下一杯ＸＯ，然後醉薰薰的唱起歌来.....还真难听!!\n",
		this_player() );

	remove();
	return 1;

}
	
