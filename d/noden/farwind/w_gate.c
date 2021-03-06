//#pragma save_binary

// translation done. 2-21-94  -Elon

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("远风镇西门");
	set_long( @C_LONG_DESCRIPTION
这里是远风镇西边的大门，路旁有一棵大树(tree)，北边是一间白色
的屋子(house)，往南是一条小路通往河边，西边出了大门是一座桥，你
听到桥下除了潺潺的流水声外，好像还有一些鹅叫声。
C_LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
		"west" : "/d/noden/farwind/bridge",
		"south" : "/d/noden/farwind/path1",
		"east" : "/d/noden/farwind/wbazz"
	]) );
	set( "item_desc", ([
		"tree" :
			"一棵又粗又大的榕树，长在路旁，也许你可以爬(climb)上去瞧瞧？\n",
		"house" :
			"一间看起来相当讲究的屋子，虽然外观有些破旧，但是屋主似乎很小\n"
			"心地保养这栋房子，屋子的门没有关，你可以进去(enter)瞧瞧。\n",
    ]) );
    set( "objects", ([
		"wild dog" : "/d/noden/farwind/monster/dog"
	]) );
	reset();
}

void init()
{
	add_action( "climb_tree", "climb" );
	add_action( "enter_house", "enter" );
}

int climb_tree( string arg )
{
	if( !arg || arg!="tree" )
		return notify_fail( "爬什麽？\n" );
        if( random( 15 ) >=this_player()->query_skill("climbing") )
		return notify_fail( "你企图爬上榕树，但是一不小心掉了下来。\n");
	this_player()->move_player( "/d/noden/farwind/tree1", "SNEAK" );
	tell_room( this_object(), 
		this_player()->query("c_name") + "爬到树上。\n",
		this_player() );
	return 1;
}

int enter_house( string arg )
{
	if( !arg || arg!= "house" )
		return notify_fail( "进入哪里？\n" );
	this_player()->move_player( "/d/noden/farwind/healer", "SNEAK" );
	return 1;
}
