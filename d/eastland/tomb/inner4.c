#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
这儿是陵墓的角落，冷冷的银光自星空洒下。你看到一些大箱子放在墙边，然而它们似
乎都被锁上了，令你颇觉懊恼。除此之外还有\许\多具兵马俑\摆\在这儿，它们的神态栩栩如生
，一个个的眼光彷佛在注视著你，你想还是赶快离开这儿的好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner3",
		"west"  : TOMB"/inner5"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"当你来到这儿时，那些兵马俑的武器突然都往你身上招呼 !!\n"
		);
	this_player()->receive_damage(100);
}
