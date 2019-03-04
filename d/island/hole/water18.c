
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "钟乳石洞穴" );
	set_long(@LONG
你忽然来到一处潮湿的洞穴，叮叮咚咚的水声由洞穴深处传来。
猛抬头一看，几根将近三尺的钟乳石上，忽然落下几滴清凉的水珠打
在你身上。刹时间你觉得彷佛置身仙境。在你的面前，几根较粗大的
钟乳石中间形成一滩小水池，里边的水看起来相当清澈，想必是由上
面的钟乳石上凝结而成的。
LONG
		);
	set( "exits",([ 
			"north" : HOLE"water19",
			"out" : HOLE"hole30",
		]) );
	set( "item_desc",([ 
	"pool" : "水池里清楚的映出你的倒影，你想喝喝(drink)里边的水吗？\n" ]) );
	set( "water_source",2 );
	reset();
	
}

void init(){ add_action( "to_drink","drink" ); }

int to_drink(string str)
{
	string him;
	object player;
	int max;

	player=this_player();
	him=player->query( "c_name" );
	max=player->query( "max_tp" );
	if( !str || str!="water" )
		return notify_fail( "喝什麽？\n" );
	tell_room( environment(player),set_color(
	him+"弯下腰，喝了一口池塘里的水，你发现"+him+"的脸上洋溢著幸福的表情。\n","HIY" ),player );
	tell_object(player,set_color(
	"你喝了一口池塘里的水後，顿时觉得喉头一阵清爽，突然想大喊几声。\n","HIY" ) );
	player->set( "talk_points",max );
	player->force_me( "shout 余誓予至诚，致死效忠 ES ，若有二心，愿请众巫师和大神PK我... " );
	return 1;
}