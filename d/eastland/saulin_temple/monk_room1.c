#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("禅房");
	set_long( @C_LONG_DESCRIPTION
这是一间不算大的房子，房子的北边放著一张大通铺，上面整整齐齐的
摆\著十几条棉被，四面的墙壁看起来斑驳不堪，应历经一段长久的岁月了，
房子虽然老旧但却一尘不染，由此可知少林僧律己之严，此处是小沙弥及知
客僧的房间。   
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
    set("objects",([
	"monka" : SAULIN_MONSTER"little_monk",
	"monkb" : SAULIN_MONSTER"little_monk",
        "monkc" : SAULIN_MONSTER"greet_monk",
        "monkd" : SAULIN_MONSTER"greet_monk",
    ]) );
	set("exits", ([
		"east" : SAULIN"stone_path0",
	]) );
	reset();	
#include <replace_room.h>
}
