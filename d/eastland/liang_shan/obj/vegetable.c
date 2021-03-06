#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	if (clonep(this_object())) {
		set_default_ob(__FILE__);
		return ;
	}
	set_name("vegetable","炒青菜");
	add( "id" , ({ "vegetable" }) );
	set_short("炒青菜");
	set_long(
		"一盘炒青菜，看来青翠可爱。\n"
	);
   	set("unit","盘");
   	set("weight", 10);
   	set("value",({ 130, "silver" }) );
	set("is_fresh",1);
}
int move(mixed ob)
{
	if ( ob && living(ob))
		call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

int eat_food(string arg)
{
		if( !arg || arg != "vegetable" ) return 0;
		write("你很高兴的吃下这盘青菜，感觉到吃素的好处。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"吃光了一盘炒青菜，然後若有所思...\n" , this_player()
		);
		this_player()->receive_healing( 3+random(2) );
	    this_player()->set("spell_points",(int)this_player()->query("spell_points")+8);
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	if ( !owner ) { 
//	what->set ("value", ({ 1, "silver" }));
//	what->set_short("坏了的炒青菜");
//	what->set_long("这盘青菜变成黄色，不能吃了。\n");
//	what->set("is_fresh",0);
	if( living(owner) )
	tell_object(owner,
		"你发现你的青菜变成了黄黄的，好像不能再吃了，你只好把它倒掉。\n" 
		);
	}
	remove();
}
