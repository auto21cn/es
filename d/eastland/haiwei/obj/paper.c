#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("kill hob paper", "收妖符");
	add( "id", ({ "paper" }) );
	set_short("收妖符");
	set_c_open_long("是收妖用的符咒，当你使用(use paper)时会降低妖物的能力。\n");
	set( "weight", 10);;
	set( "max_load", 250);
	set( "value", ({ 0, "silver" }));
}

void init()
{
  add_action("do_use","use");
 }

int do_use(string arg)
{

//  if(arg="paper")
 
     
}