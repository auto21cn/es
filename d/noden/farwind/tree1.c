//#pragma save_binary

// Unos translacion de Platino, Mar 4 2:33:23 1994

#include <mudlib.h>

inherit ROOM;

int beehive = 0;

void create()
{
	::create();
    set_short( "榕树上");
	set_long( @C_LONG_DESCRIPTION
你轻而易举地便爬上了这棵榕树，从树上往下看可以看到远风镇的西门
和旁边的一间白色小屋，咦....啊....就在离你一公尺不到的地方有一个西
瓜大的蜂窝(beehive) ，蜜蜂嗡嗡的声音似乎就在你的耳边，还是赶紧离开
这个地方以免惊动它们。
C_LONG_DESCRIPTION
	);

	set( "exits", ([
		"down" : "/d/noden/farwind/w_gate"
	]) );
	set( "objects", ([
		"witch" : "/d/noden/farwind/monster/witch" ]) );
	set( "item_desc", ([
        "beehive" :
			"一个和西瓜差不多大的蜂窝，你最好不要靠太近，以免蜜蜂受到惊扰。\n",
	]) );
    reset();
}

void init()
{
	add_action( "do_hit", "hit" );
	if( this_player() ) this_player()->set_explore("noden#0");
}

int do_hit(string arg)
{
	object obj;
	int i;

	if( !arg || arg!="beehive" ) return 0;
	write( "你蹑手蹑脚地靠近蜂窝，往蜂窝用力一敲！\n");
	tell_room( this_object(), 
		this_player()->query("c_name") + "蹑手蹑脚地靠近蜂窝，然後在上面用力一敲！\n",
		this_player() );
	if( beehive ) return 1;
	beehive = 1;
	for( i=0; i<6; i++ ) {
		obj = new( "/d/noden/monster/hornet" );
		obj->move(this_object());
	}
	for( i=0; i<3; i++ ) {
		obj = new( "/d/noden/monster/hornet_soldier" );
		obj->move(this_object());
	}
	
	this_player()->set_explore( "noden#3" );
	
	this_player()->gain_experience(100);
	write( "你得到 100 点经验。\n" );
	return 1;
}
