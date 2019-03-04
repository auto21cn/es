#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
这儿是陵墓的角落，冷冷的银光自星空洒下。你看到\许\许\多多的大箱子放在墙边，然而
它们似乎都被锁上了，令你颇觉懊恼。箱子旁有一面高大的铜镜，一阵阵刺目的闪光自铜镜
中发出，照的你头晕目眩，你想还是赶快离开这儿的好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north" : TOMB"/inner7",
		"east"  : TOMB"/inner1"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"当你来到这儿时，铜镜中突然发出一道强光穿过你的身体 !!\n"
		);
	this_player()->receive_special_damage("electric",100);
}
