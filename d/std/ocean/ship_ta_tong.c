#include <mudlib.h>
#define ROOM_OBJ "/d/std/ocean/room_ta_tong"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Haiwei", "海威港", "/d/eastland/haiwei/jetty", 30, 80 }),
   	({ "Deathland", "死亡大地", "/d/deathland/main/d1", 30, 80 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "Ship of Ta-Tong", "大通号渔船" );
	add( "id", ({ "ship", "ta-tong" }) );
	set_short( "大通号渔船" );
	set( "long", "@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

string query_c_long()
{
	return
		"这是一艘叫做大通号的老旧渔船，你如果想要搭乘大通号，可以\n"
		"用 board 指令搭船。\n"
		"大通号的下一个目的地是" + schedule[(loc+1)%sizeof(schedule)][1] + "。\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->move_player( ROOM_OBJ, ({
		"%s走上大通号渔船。\n",
		"%s从码头登上大通号。\n" }) );
	return 1;
}

// This function announce the ship is sailing in advance (20 seconds)
void announce()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"大通号的船老大大叫: 快要开船啦！下一站是" + schedule[next_loc][1] + "！\n" );
	tell_room( environment(this_object()), 
		"大通号的船老大大叫: 快开船啦！下一个目的地是" + schedule[next_loc][1] + "，要上船的客人请赶快！\n" );
	call_out( "lets_go", 20 );
}

// This function sails the ship into the ocean.
void lets_go()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"大通号的船老大大叫: 出发罗！\n"
		"你感到大通号像脱□的野马般的大摇特摇，大通号离开了码头 ....\n" );
	tell_room( environment(this_object()), 
		"大通号的船老大大叫: 出发罗！\n"
		"大通号缓缓地开出港口，航向辽阔的大海 ....\n" );
	call_out( "arrive", schedule[loc][4] );
	ROOM_OBJ->set_location( "ocean" );
	loc = next_loc;
}

// This function sails the ship into the ocean.
void arrive()
{
	object ship_room;

	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][2] );
	tell_room( ship_room, 
		"大通号的船老大大叫: " + schedule[loc][1] + "到罗 ! 人客们赶快下船吧 !\n" );
	tell_room( environment(this_object()), 
		"你看到大通号缓缓地开进码头 ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}

