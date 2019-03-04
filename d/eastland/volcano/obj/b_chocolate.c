#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "blue_chocolate", "蓝色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short(  "蓝色巧克力" );
	set_long(
		"这是一个包著神秘礼物的巧克力，你可以□□看(taste)。\n"
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
   int fp,maxfp;

   if(!arg || arg!="chocolate")
   { write("你要吃什麽？\n");
     return 1;
   };

   write("你吃了这块巧克力，吓!竟然一只鸡腿藏在里面。\n");
   write("你吃了之後发现肚子咕噜咕噜直叫，看来不跑厕所不行了。\n");
   maxfp=this_player()->query("max_fp");
   fp=this_player()->query("force_points");
   if (maxfp<(fp+10))
     this_player()->set("force_points",maxfp);
   else
     this_player()->set("force_points",fp+5);
   this_object()->remove();
   return 1;
}
