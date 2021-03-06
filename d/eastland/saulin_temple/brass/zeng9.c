#include <almuhara.h>
#define SLAB_FILE "/d/eastland/data/brassman.txt"

inherit ROOM;

void create()
{
        ::create();
        set_short( "铜人阵中" );
        set_long(
@C_LONG
你进入了一个宽广的石室，这儿和前面几间石室唯一不同的是，竟
然没有铜人在这里 !! 在你面前的是一个巨大的铜香炉(censer)，袅袅
的暗香在空间中浮动著，令人精神一振。你心想这其中必有古怪，还是
静下心来好好想想吧....
C_LONG
        );

	set( "time",0);
        set( "light",1 );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        add( "item_desc", ([
        	"censer" :
"这是一个巨大的香炉，上面铸著罗汉降龙伏虎之像。你忽然想到在
小时候的印象中，想过铜人阵好像要搬开(move)大香炉喔...\n"
	]) );
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
	add_action("do_songin","songin");
	add_action("do_move","move");
}

void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
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
		this_object()->set("time",0);
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
		this_object()->set("time",0);
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_auction()
{
	return 1;
}

int do_songin()
{
	object obj;
	obj = this_player();
	if( !query_temp("alignment") ) {
		set_temp("alignment",obj->query("alignment"));
		return 0; }
	if( obj->query("alignment") > 10000 ) {
		this_object()->add("time",1);
		if( (int)this_object()->query("time") > (4+random(3)) ) {
			new("/d/eastland/saulin_temple/brass/obj/brassman6")->move(this_object());
			new("/d/eastland/saulin_temple/brass/obj/brassman7")->move(this_object());
			new("/d/eastland/saulin_temple/brass/obj/brassman8")->move(this_object());
			return 1; }
		return 0; }		
	else if( ((int)obj->query("alignment")-(int)query_temp("alignment")) > 500 ) {
		new("/d/eastland/saulin_temple/brass/obj/brassman6")->move(this_object());
		new("/d/eastland/saulin_temple/brass/obj/brassman7")->move(this_object());
		new("/d/eastland/saulin_temple/brass/obj/brassman8")->move(this_object());
		return 1; }
	else return 0;
}
	
int do_move(string str)
{
	object obj,ob1;
	string fame;
	seteuid(getuid());
	obj = this_player();
	
	if( !str || str == "" ) return 1;
	
	if( str == "censer" ) {
		if ( !obj->query_temp("be_k") ) {
			tell_object(obj,
				 "奇怪 !! 你怎样都搬不动它耶。\n");
			return 1; }
		tell_object(obj,
			"你使劲去搬动香炉，忽然一阵大力将你向外送出去 !!\n" );
		announce(
set_color("\n突然从少林寺方向传来阵阵钟声～～～\n"
"\n铜人阵长老慧元大声喊道： 恭禧 "+obj->query("c_name")+" 顺利通过十八铜人阵的\n"
"考验 ！！\n\n","HIB") );
		this_object()->set("time",0);
		obj->set("18brass",1);
		obj->move_player(SAULIN"/entrance","SNEAK");
		fame = "     "+(string)this_player()->query("c_name")+"("+
		(string)this_player()->query("name")+")"+" 於 "+
		"/adm/daemons/weather_d"->query_c_game_time()+" 过阵 !!\n";
		write_file(SLAB_FILE, fame+"\n");
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("你看到%s大摇大摆的走了出来，一副很臭屁的样子。\n",
			obj->query("c_name") ),obj );
		ob1->set("enter",0);
		reset();
		return 1; }
	return 1;
}
