
#include <mudlib.h>
#define SHIP_OBJ "/d/std/ocean/ship_death"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "ship of darkmerchant", "黑暗商人号");
	add( "id", ({ "ship", "darkmerchant" }) );
	set_short("黑暗商人号");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "ocean" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"你现在正站在黑暗商人号的船里, 一艘有点破旧又不会太破旧的中型船, 一种特殊\n"
"的死蓝色掺杂著的灰白色的斑点, 更显得这艘船似乎将驶向恐怖的地方。\n";
	switch( location ) {
		case "Bluesand":
			long += "    黑暗商人号现在正停泊在蓝沙港的码头上。\n";
			break;
		case "Deathland":
			long += "    黑暗商人号现在正停泊在死亡大地的码头边。\n";
			break;
		case "ocean":
		default:
			long += "    黑暗商人号现在正航行在一望无际的大海上。\n";
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
