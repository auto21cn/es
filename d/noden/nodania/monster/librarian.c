#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "librarian", "图书馆员" );
	set_short( "图书馆员" );
	set_long(@CLONG
这位看起来很斯文秀气的小姐就是诺达尼亚大图书馆的图书馆员，你如
果想找什麽书，只要问(ask)她所要找寻的主题，她就会帮你找书。
CLONG
	);
	set( "no_attack", 1 );
	set( "gender", "female" );
	set( "race", "elf" );
	set( "inquiry", ([
		"ALL_TOPIC" : "@@seek_book"
	]) );
}

void seek_book( object player )
{
	tell_object( player,
		"图书馆员对你说道: 很抱歉，最近图书馆正在整修，暂停借书....。\n"
	);
}
