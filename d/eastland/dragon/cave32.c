
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("森林");
	set_long( @LONG_DESCRIPTION
这里是一座古老的原始森林，这里的所有树木看起来都是古老而沧桑，彷佛历经无
数岁月的磨练，但当你走在森林步道上，耳听黄莺清脆的鸣叫并享受芬多精的薰陶，这
一切切都让冒险者的心，不知不觉中平静下来。
LONG_DESCRIPTION
	);
	set_outside("dragoncave");
	set( "light", 1 );
	set( "exits", ([
		"east"  : Lcave"cave18"
	]) );
	reset();
}

void init()
{
 add_action("do_search","search");
 }

int do_search(string arg)
{
	object ob1,ob2,ob3;
	
	ob1=(object)Lcave"cave18"; 
    if (!arg) arg="here";
	if( arg!="here")
		return notify_fail( 
			"你在这里中找来找去，但并没有找到任何奇特的东西。\n");

    else if ((int)ob1->query("room_control")==2&& !ob1->query("tree_find"))  {
        ob2=new(Lditem"layuter_tree");
        ob3=environment(this_player());
        ob2->move(ob3);
		write("一棵神秘的树突然从你的眼前冒出。\n");

		ob1->set("tree_find",1);
		return 1;
	}
	return notify_fail( 
		"你在这里中找来找去，但并没有找到任何奇特的东西。\n");

}
