#include <mudlib.h>
#include <ansi.h>
inherit OBJECT;

void init()
{
        add_action( "eat_food", "eat" );
}

void create()
{
        
set_name("red fruit","朱果");
        add( "id" , ({ "fruit" }) );
   set_short(""+HIR"朱果"+NOR"");
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
        "你吃下了一颗朱果，口中满是芳香。\n突然你感到全身发热，一股强烈的气在身体中到外流串! \n");
       this_player()->set("max_hp",5000);
       this_player()->set("max_sp",5000);
    this_player()->receive_healing( 5000 );
    this_player()->add("force_points",5000);
      this_player()->add("spell_points",5000);
       remove();
    return 1;
}
