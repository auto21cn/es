#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("少林寺大门");
	set_long( @C_LONG_DESCRIPTION
在你的眼前有一座雄伟的山门，上面以龙飞凤舞的笔迹书写著「少林寺」
三字，听说这是东方皇帝的真迹，以表扬少林寺对东方武术的贡献，你的左右
两方个是一片高耸的围墙，它把整个少林寺环绕起来，使得少林寺更增神秘，
门前则是一条云石阶梯，那是少林寺对外主要道路。 
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
	set("no_monster", 1);
	set("objects",([
	    "monk1" : SAULIN_MONSTER"greet_monk",
	    "monk2" : SAULIN_MONSTER"greet_monk",
	    "monk3" : SAULIN_MONSTER"greet_monk",
	    "monk4" : SAULIN_MONSTER"greet_monk",
	]) );
	set( "pre_exit_func", ([
		 "enter" : "check_weapon",
	]) );
	set( "exits", ([
		 "enter" : SAULIN"front_square2",
		 "down"  : SAULIN"road4",
	]) );
	reset();
}

int is_a_weapon(object item)
{
	if( item->query("weapon_class") && !item->query("prevent_drop")) 
		return 1;
	return 0;
}

int check_weapon()
{
	object *weapons;
	weapons = filter_array( all_inventory( this_player() ),
			"is_a_weapon", this_object() );
	if( wizardp(this_player()) || !weapons || !sizeof(weapons) || 
		!present("monk") ) return 0;
	tell_object( this_player(), 
		"知客僧说道: 施主, 对不起, 少林寺内戒杀, 请放下您的武器。\n" 
	);
	return 1;
}
