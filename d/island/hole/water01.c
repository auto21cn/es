
#include <hole.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "水底" );
	set_long(@LONG
这是一处地下水汇集的的地层，蜥蜴人日常的饮用水
就是由此处供应的。不过这里的水相当混浊，你甚至怀疑
这种水真的可以喝吗？
LONG
		);
	set( "exits",([ 
			"southeast" : HOLE"water02",
		]) );
	set( "objects",([ "crystal" : HOBJ"amethyst" ]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
	add_action( "to_out","out" );
}

int to_out()
{
	string him;
	
	him=this_player()->query( "c_name" );
	tell_room( environment(this_player()),set_color(
	him+"受不了水底环境，决定先出去喘口气。\n","HIR"),this_player() );
	this_player()->move( HOLE"hole24","SNEAK" );
	this_player()->force_me( "look" );
	tell_room( environment(this_player()),set_color(
	him+"忽然从你面前的池塘中冒了出来。\n","HIY"),this_player() );
	return 1;
}