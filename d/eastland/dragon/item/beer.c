// This is a standard healing potion. 
// Created by Annihilator@Eastern.Stories 11-22-93
#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name( "chinese beer", "陈年女儿红" );
        add( "id",({ "beer" }) );
        set_short( "陈年女儿红" );
        set_long(
            "这是由一个古老的国家所传下的名酒。\n"
        );
        set("layuter_beer",1);
        set( "unit", "瓶");
        set( "weight", 10 );
        set( "value", ({ 20, "gold" }) );
}


void init()
{
	add_action( "drink_beer", "drink" );
}

int drink_beer(string arg)
{
	int kar, heal;
	string unit;

	if( !arg || (arg!="beer") ) return 0;
	if( environment() != this_player() )
		return notify_fail("你身上没有这样东西。\n");
	write("你喝下一喝下一瓶陈年女儿红。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下一瓶陈年女儿红。\n",
		this_player() );
	heal = 20;
	this_player()->receive_healing( heal );
	remove();
	return 1;
}
