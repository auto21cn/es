#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
这儿是陵墓的角落，冷冷的银光自星空洒下。你看到\许\许\多多的大箱子放在墙边，然而
它们似乎都被锁上了，令你颇觉懊恼。从脚底下传来阵阵的热气，你想还是赶快离开这儿的
好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north" : TOMB"/inner3",
		"west"  : TOMB"/inner1"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"当你来到这儿时，一片火焰突然由你脚下冒起 !!\n"
		);
	this_player()->receive_special_damage("fire",100);
}
