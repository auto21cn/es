// File: 5,4.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;
int no_branch;

void create()
{
	::create();
	set_short("桃花林");
	set_long( @LONG_DESCRIPTION
你身处在一片美丽的桃花林中，这里正是所谓的『落英缤纷，芳草鲜
美』，要是仔细观察此处的桃树，你会发现它们以某种奇怪的次序排列著
，但你又看不出人力斧凿的痕迹，或许是浑然天成的吧；在这里站的越久
，你越觉得世间的名利斗争已经离你远去，这种心旷神怡的感觉，使你对
儿流连忘返；南边和西边有条小河，但是有点深，小心唷！	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,4.island", 
		"north" : ISLAND"5,3.island", 
		"east"  : ISLAND"6,4.island",
		"south" : ISLAND"5,5.island",
		]) );
	set( "original", ISLAND"5,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 4 );
	no_branch=0;
	reset();
}

void init(){ add_action( "to_mill","mill" ); }

int to_mill( string arg )
{
	string target,tool;
	object obj;

	if( !arg || sscanf(arg,"%s with %s",target,tool)!=2 )
	return notify_fail( "Usage: mill <目标> with <工具> \n" );
	if( target!="tree" ) 
	return notify_fail( "这把斧头只能砍树木。\n" );
	if( tool!="saw" )
	return notify_fail( "用手锯吗？\n" );
	if( !present( "saw",this_player() ) )
	return notify_fail( "糟糕！你忘了带锯子来！\n" );
	if( no_branch < 4 ){
	tell_object(this_player(),
	"\n你费了九牛二虎之力，终於找到一棵合适的桃树，锯下一根树枝！\n\n" );
	obj=new( "/d/island/hole/obj/branch" );
	obj->move( this_player() );
	this_player()->set_explore("island#8");
	no_branch=no_branch+1;
	return 1;
	}
	tell_object(this_player(),"\n不知道哪个奸商把这里的桃木全砍了。\n\n" );
	return 1;
}
