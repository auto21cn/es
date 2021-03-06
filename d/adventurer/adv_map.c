//#pragma save_binary

#include <mudlib.h>
#include "adventurer.h"

inherit GUILD_OB;
inherit MAP;
inherit OBJECT;

void create()
{
	guild_ob::create();
	seteuid(getuid());
	set_class_name("adventurer");
	set_size( 7, 7 );
#include <compress_obj.h>
	set_name("map", "地图");
	set_short("冒险专用地图");
	set_long(@LONG
这是一张十分著名的冒险者专用地图，由一位当年发现通往东方大国
的伟大冒险者所绘制而成。对年青的冒险者可以提供很大的帮助，请
参阅\ help map 以获得进一步的说明。
LONG
	);

	set( "unit", "张" );
	set( "weight", 5 );
	set( "extra_look", "$N带著冒险者专用的魔法地图。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	// Apply map functions
	std_map::init();
	
	add_action("help", "help");
	add_action("info", "info");
	add_action("do_check", "check" );
	add_action("do_fellows", "fellows");
	add_action("do_chat", "adv");
}

int do_check(string str)
{
	object dest;
	int my_level, dest_level;

	if( !str || str=="" || !(dest= present(str, environment(this_player()))) )
		return notify_fail("指令格式: check <怪物>\n");
	my_level = (int)this_player()->query_level();
	dest_level = (int)dest->query_level();
	if( my_level < dest_level ) write("对方的等级比你高。\n");
	if( my_level == dest_level ) write("对方和你同等级。\n");
	if( my_level > dest_level ) write("对方的等级比你低。\n");
	return 1;
}

int do_fellows()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("你想对其它冒险者说什麽？\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA+"c_adv_history" );
			break;
	    case "commands": cat( GUILD_DATA+"c_adv_commands" );
			break;
		case "topics":
		default: 
write( @C_TOPICS
冒险者公会是一个属於所有人的公会，你可以用 info 指令取得有关以下主题的资
讯:
    history    - 有关冒险者公会的历史。
    commands   - 有关冒险者能使用的特殊指令。
    
C_TOPICS
			);
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="map" ) return 0;
	cat(GUILD_DATA+"c_adv_map");
	return 1;
}
