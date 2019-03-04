#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "red_chocolate", "红色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short(  "红色巧克力" );
	set_long(
		"这是一个包著牛奶的巧克力，你可以□□看(taste)。\n"
	);
	set( "type", "misc" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","taste");
}

int do_eat(string arg)
{
   int tp,maxtp;

   if(!arg || arg!="chocolate")
   { write("你要吃什麽？\n");
     return 1;
   };

   write("你吃了一块包著牛奶的巧克力，它慢慢的化在嘴里，牛奶也跟著慢慢的流出。\n");
   write("你感到说不出的舒服，真想再吃一块。\n");
   maxtp=this_player()->query("max_tp");
   tp=this_player()->query("talk_points");
   if (maxtp<(tp+10))
     this_player()->set("talk_points",maxtp);
   else
     this_player()->set("talk_points",tp+10);
   this_object()->remove();
   return 1;
}
