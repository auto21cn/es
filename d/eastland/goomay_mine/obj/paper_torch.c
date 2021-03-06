

#include "../zeus.h"
inherit OBJECT;

void create()     
{
	set_name( "magic_paper", "千里火" );
	set("short", "@@query_short");
	set("long", "@@query_long");
	set("id", ({ "paper" }));
	set( "unit", "张" );
	set("weight", 5);
	set("fuel", 300);  // fuel is measured in seconds
}


void init()
{
	add_action("light_t", "blow");
	add_action("extinguish_t", "unlight");
}        
int light_t(string str)
{
	if(!id(str)) return 0;	

	if(query("light")) 
		return notify_fail( "这张千里火已经点著了。\n");

	write("你吹了一口气将千里火给点著了。\n");
	set("light", 1);
	this_player()->set_temp("paper/light",1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;	
	if(!query("fuel"))
		return notify_fail( "来不及了!这张千里火已经化为飞灰了。\n");	
	if(!query("light"))
		return notify_fail("这根千里火还没有点著，如何熄灭？\n");

	write("你将摇一摇手将千里火熄灭。\n");
	set("light", 0);
	this_player()->set_temp("paper/light",0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{       object ob; 
	object owner;
           ob = this_object();
	owner = environment(this_object());
	if( living(owner) ){
		tell_object( owner,"你的千里火火光闪了几下，化成灰熄掉了。\n");
       ob->remove();
       this_player()->set_temp("paper/light",0);
	}
}

string query_short()
{
	if(query("fuel"))
		return "千里火" + (query("light") ? " (点著)" : "");
}


string query_long()
{
	if(query("fuel"))
		return "千里火是最古代常见的随身光源，\n" +
			(query("light") ? "这张千里火已经点著了，你可以熄灭(unlight)它。\n"
			: "你可以对它吹(blow)口气点燃使用。\n");
}
