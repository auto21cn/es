// File: /d/ocean/ship_iriah.c
// Generated by Roommaker Mon Dec 27 18:39:52 1993

#include <mudlib.h>
#define SHIP_OBJ "/d/std/ocean/ship_iriah"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "frigate iriah", "依莉雅号帆船");
	add( "id", ({ "frigate", "iriah" }) );
	set_short("依莉雅号帆船");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "ocean" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"你现在正站在依莉雅号帆船的甲板上，依莉雅号是一艘大型的多桅帆船，漆\n"
"成淡蓝色的船身和乳白色镶黄边的巨帆，衬托出这艘美丽的帆船所独有的一种高\n"
"贵气质，据说这艘帆船是在诺顿王国的皇后依莉雅二十岁生日那天，蓝沙港的居\n"
"民献给皇后的生日礼物。\n";
	switch( location ) {
		case "Bluesand":
			long += "    依莉雅号现在正停泊在蓝沙港的码头上。\n";
			break;
		case "Haiwei":
			long += "    依莉雅号现在正停泊在海威港的码头边。\n";
			break;
		case "ocean":
		default:
			long += "    依莉雅号现在正航行在一望无际的大海上。\n";
			break;
	} 
	return long;
}

// This function sets the location of the ship.
varargs void set_location( string new_loc, string exit )
{
	location = new_loc;
	if( location=="ocean" || !exit ) {
		set( "exits", ([]) );
		SHIP_OBJ->move( "/d/std/ocean/ocean" );
	} else {
		set( "exits", ([ "out": exit ]) );
		SHIP_OBJ->move( exit );
	}
}

