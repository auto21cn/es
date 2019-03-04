#include "/d/noden/nodania/nodania.h"
inherit "/d/noden/tamumu/monster/guard.c";
void create()
{
	::create();
	set_level(5);
	set_name( "flesheater", "肉食兽" );
	set_short( "肉食兽" );
	set( "post_name","'s flesheater" );
	set( "c_post_name","驯服的肉食兽" );
	set_long(
		"肉食兽....\n"
	);
	setenv( "C_MMIN","$N走了过来。");
	setenv( "C_MMOUT","$N跟著主人离开。");
	
	set( "gender", "male" );
	set( "war_score", 1 );
}

void init()
{
	add_action("do_send","send");
}

int do_send(string s)
{
	if (!s || s != "flesheater back")
		return 0;
	if (this_player()->query_temp("control_flesh") != 2)
		return 0;
	tell_object(this_player(),@LONG
肉食兽知道你不再需要他了，耸耸肩就回家去了。
LONG
	);
	this_player()->delete_temp("now_guard");
	this_object()->remove();
	return 1;
}
