#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
	set_name("red fruit","朱果");
	add( "id" , ({ "fruit" }) );
   set_short("朱果");
   set_long(@C_LONG
一颗赤红色的果实，散发出浓郁的芳香，看起来很好吃的样子。
C_LONG
	);
   	set("unit","颗");
   	set("weight", 30);
   	set("no_sale",1);
   	set("value",({ 500, "silver" }) );
}

int eat_food(string arg)
{
    if( !arg ||( arg != "fruit") ) 
        return notify_fail("你要吃啥东西咩?\n");
    tell_object( this_player(),
        "你吃下了一颗朱果，口中满是芳香。\n");
    this_player()->receive_healing( 50 );
    this_player()->add("force_points",50);
    remove();
    return 1;
}
