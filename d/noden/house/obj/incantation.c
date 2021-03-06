#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "incantation of exorcise", "驱魔咒" );
	add( "id", ({ "incantation" }) );
	set_short( "驱魔咒" );
	set_long(
		"这张驱魔咒是一张黄色的纸，上面画满弯弯曲曲的线条和符号，要使用\n"
		"驱魔咒，用 zap <someone>。\n"
	);
	set( "unit", "张" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_zap", "zap" );
}

int do_zap(string arg)
{
	object obj;

	if( !arg || arg=="" || !(obj= present(arg, environment(this_player()))) )
		return notify_fail( "要对谁使用驱魔咒？\n");
	if( base_name(obj) != "/d/noden/house/monster/devil" ) {
		write( 
			"你拿出驱魔咒在" + obj->query("short") + "面前挥舞，不过对方似乎不受影响。\n");

		tell_room( environment(this_player()), 
			this_player()->query("c_cap_name")+ "拿出一张黄色符咒在"+obj->query("short")+"面前挥舞。\n",
			this_player() );
		return 1;
	} else {
		write("你拿出驱魔咒在" + obj->query("short") + "面前挥舞 .... \n");
		tell_room( environment(this_player()), 
			this_player()->query("c_cap_name")+ "拿出一张黄色符咒在"+obj->query("short")+"面前挥舞。\n",
			this_player() );
		obj->zapped();
		write("你的驱魔咒突然自己飞了出去，紧紧贴在" + obj->query("short") + "身上！\n");
		remove();
		return 1;
	}
}
