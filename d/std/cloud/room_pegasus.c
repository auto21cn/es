#include <mudlib.h>
#define SHIP_OBJ "/d/std/cloud/airship_pegasus"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "airship pegasus", "天马号帆船");
	add( "id", ({ "airship", "pegasus" }) );
	set_short("天马号帆船");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "cloud" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"你现在正站在天马号飞船的甲板上，三根巨大的桅杆撑起两幅碧蓝色的巨帆，占\n"
"去了飞船後方一大半的空间，这艘飞船原本是默尔斯人进贡东方大国皇帝的礼物，不\n"
"过由於皇帝对默尔斯人并不信任，这艘飞船辗转到了一个诺达尼亚商人的手中，现在\n"
"它已经成了富有的旅行者最方便快速的交通工具。\n";
	switch( location ) {
		case "Easta":
			long += "    天马号现在正停在若岚城西门外的载客站。\n";
			break;
		case "Nodania":
			long += "    天马号现在正停在诺达尼亚城外的载客站。\n";
			break;
		case "cloud":
		default:
			long += "    天马号现在正飞在辽阔的天空中。\n";
			break;
	} 
	return long;
}

// This function sets the location of the ship.
varargs void set_location( string new_loc, string exit )
{
	location = new_loc;
	if( location=="cloud" || !exit ) {
		set( "exits", ([]) );
		SHIP_OBJ->move( "/d/std/cloud/cloud" );
	} else {
		set( "exits", ([ "out": exit ]) );
		SHIP_OBJ->move( exit );
	}
}
