#include <mudlib.h>

inherit OBJECT;

int cutted;

void create()
{
    set_name( "wolf heart", "狼心" );
    add( "id", ({ "heart" }) );
    set_short( "狼心" );
    set( "unit", "颗" );
	set("long","@@query_c_long");
    set( "weight", 10 );
    cutted = 0;
}

string query_c_long()
{
    if( cutted )
        return "这是一颗被切成一团稀烂的狼心, 你越看越感恶心。\n";
	else
        return "这是一颗血淋淋的狼心, 似乎没什麽利用价值。\n";
}

int query_cutted() { return cutted; }

void init()
{
    add_action( "cut_heart", "cut" );
}

int cut_heart(string arg)
{
    object cleaver;

    if( !arg || ( arg!="heart" && arg!="wolf heart") )
        return notify_fail("你要切什麽东西？\n");
    if( cutted )
        return notify_fail("这颗心已经被切过了。\n");

    cleaver = present("cleaver",this_player());

    if( !present("cleaver",this_player()) )
        return notify_fail("你最好找把适当的刀来切它。\n");

    cutted = 1;
    write("你拿起屠刀把狼心大解八块。\n");
	return 1;
}


