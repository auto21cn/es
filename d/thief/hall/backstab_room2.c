#include <mudlib.h>
#include "../thief.h"
inherit ROOM;
#define TEST_ROOM "/d/thief/hall/backstab_room"
init()
{
	add_action("do_auc","auction");
	add_action("do_quit","quit");
}

do_auc()
{
	tell_object(this_player(),"你不能在这里进行交易!!\n");
	return 1;
}

do_quit()
{
	TEST_ROOM->delete("begin_test");
	TEST_ROOM->delete("tester");
	TEST_ROOM->set("using",0);
        tell_object(this_player(),
                "一个声音说道 : 放弃啦? 好吧, 下次再试试看可能比较好。\n");
//	TAYLERS->chat("测试讯息\n");
	return 1;
}

void create()
{
	::create();
	
	set("light", 1);
	set_short( "背刺测验室" );
	set_long( @LONG
这是一间宽敞的房间，里面\摆\满了大大小小的箱子，很适合藏身，
是专门设计用来作为训练场的。
LONG
	);

	set("exits", ([
		"north" : "/d/thief/hall/pathway",
		"south" : TEST_ROOM,
	]) );
	set("pre_exit_func",([
		"north" : "pass_test" ]) );
	reset();

/*
create_door("north","south",([
             "keyword" : ({"door" }),
             "status" : "locked",
             "c_desc" : "一扇结实厚重的铁门",
             "c_name" : "铁门",
             "name":"iron door",
             "desc":"an iron door",
             "lock" : "backstab_room2",
              ]) );

*/	
}

int pass_test()
{
	object *inv;
	int i;
	if ( present("maskman",this_object()) ) {
		tell_object(this_player(),
		"蒙面人伸手把你拦住，不让你通过。\n");
		return 1;
	}
	if ( !this_player()->query_temp("pass_test") )	return 0;
	this_player()->delete_temp("pass_test");
	this_player()->delete_temp("skip_dead");
	this_player()->add("thief_level/backstab",1);

	TEST_ROOM->delete("begin_test");
	TEST_ROOM->delete("tester");
	TEST_ROOM->set("using",0);

	tell_object(this_player(),
		"你兴奋地穿过铁门。\n"
		"经过这次的战斗训练，你的背刺能力提升到了第 "+this_player()->query("thief_level/backstab")+" 级 !!\n");
	TAYLERS->chat("恭喜" + this_player()->query("c_name") + "通过背刺测验 !!");
	return 0;
}

