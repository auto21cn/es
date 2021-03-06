//#pragma save_binary

#include <mudlib.h>
#include "knight.h"

inherit GUILD_OB;
inherit WEAPON;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set_class_name("knight");
#include <compress_obj.h>
	set_name("sabre", "佩刀");
	set_short("黄金佩刀");
	set_long( @LONG
这是一把属於诺顿骑士团成员的黄金佩刀，这把佩刀也许并不是最好的武器，
但是它代表骑士的荣誉与生命。你可以用 help sabre 得到有关这把佩刀的进
一步说明。
LONG
	);

	set( "unit", "把" );
	set( "weapon_class", "@@query_weapon_class" );
	set( "type", "longblade" );
	set( "min_damage", "@@query_min_damage" );
	set( "max_damage", "@@query_max_damage" );
	set( "wield_func", "wield_sabre" );
	set( "weight", 60 );
	set( "extra_look", "$N带著一把象徵骑士的军刀。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_knights", "knights");
	add_action("do_chat", "knight");
}

int query_weapon_class() { return 10; }
int query_min_damage() { return 5; }
int query_max_damage() { return 10; }

void wield_sabre()
{
	write("你将配刀从刀鞘中抽出来，向诺达尼亚王宫的方向行了一个军礼。\n");
    tell_room( environment(this_player()),
		this_player()->query("c_name")+"抽出黄金配刀，行了一个漂亮的军礼。\n",
		({ this_player()}) );
}

int do_knights()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail( 
			"你想对其它骑士说什麽？\n");

	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA"c_kni_history" );
			break;
		case "commands": cat( GUILD_DATA"c_kni_commands" );
			break;
		case "topics":
		default: 
			cat ( GUILD_DATA"c_topics");
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="sabre" ) return 0;
	cat( GUILD_DATA"c_sabre");
	return 1;
}
