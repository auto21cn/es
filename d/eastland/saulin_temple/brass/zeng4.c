#include <almuhara.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "铜人阵中" );
        set_long(
@C_LONG
你进入了一个较小的石室，环顾四周空无一物，只有在墙上挂了张
卷轴(scroll)。看来这儿是用来让闯关的人稍做休息之用，在经历了刚
才的大战後，你不禁感激当初做此设计的人。
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng5"
        ]) );
        add( "item_desc", ([
        	"scroll" :
"恭禧你顺利通过第二关 !! 
下一关是考验你棍法上的造诣，请先准备好再往前走。\n"
	]) );  
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
}

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"突然两个红衣罗汉自墙中暗门走出，将你抬了出去。\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("你看到两个红衣罗汉将%s像抬猪公一样抬了出来。\n",
				obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"突然两个红衣罗汉自墙中暗门走出，将你抬了出去。\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("你看到两个红衣罗汉将%s像抬猪公一样抬了出来。\n",
			obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_auction()
{
	return 1;
}