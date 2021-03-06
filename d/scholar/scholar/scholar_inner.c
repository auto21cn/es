#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Scholar Inner room", "墨竹轩");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你现在进入了书生公会内部的墨竹轩，这里是书生们习武的地方，只有书生
公会的人才能进来，大厅中央有一本记载浩然正气心法的书(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
书上以草书龙飞凤舞地写著[浩然正气心法]，如果你要学习此心法必须是书生公
会的会员，如果你是的话只要下 study inner_force 你将会学到此内功\心法。
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
	  "east"  : "/d/scholar/scholar/hall", ]) );
	reset();
}

void init()
{
	add_action("to_study","study");
}

int to_study(string arg)
{
	if( !arg || arg!="inner_force" ) return 0;
	if( (string)this_player()->query("class") !="scholar" )
		write("抱歉你不是本公会的人所以你不能学此心法\n");
	else if( (int)this_player()->query("force_effect") > 1 )
		write("你已经学过此心法不能再学\n");
	else {
		write("你经过一段长时间的的学习，终於领悟到浩然正气功\的内涵\n");
    	this_player()->set("force_effect", 2);
	}
	return 1;
}
