#include "../takeda.h"
inherit OBJECT;

void create()
{
     set_name("crumb","面包屑");
     set_short("crumb","面包屑");
     set_long(
      "一小块吃剩的面包屑，给人吃是绝对吃不饱的。\n"
      );
     set( "unit", "团");
     set("weight",5);
}
void init()
{
	add_action( "eat_food", "eat" );
}
int eat_food(string arg)
{
	if( !arg || arg != "crumb" ) return 0;
        write(
                "你把这一小团面包屑吃下肚子，就好像在大海中丢入一颗石头。\n" );
        tell_room( environment(this_player()),"你看到"+
                     this_player()->query("c_name")+"狼吞虎□地吃掉了一块面包屑，"
                "你的同情心油然而生...\n", this_player()
		);
           this_player()->receive_healing( 1+random(1) );
	remove();
	return 1;
}

