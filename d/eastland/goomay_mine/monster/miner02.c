#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(14);
	set_name( "miner", "矿工" );
	add( "id", ({ "miner" }) );
	set_short( "矿工" );
	set_long(
		"一个正在辛勤努力工作的工人\n"
	);
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 13 );
	set_perm_stat( "int", 13 );

	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 20);
	set_natural_weapon( 25,15,30 );
	set( "time_to_heal", 2 );
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set( "gender", "male" );
	set( "race","dwarf");
	set( "alignment", 200 );
	set( "wealth/silver", 200 );
        set( "inquiry",([
             "detonation" : "我不清楚，发生爆炸时我不在这里．\n",
     		 ]));
	wield_weapon("/d/noden/moyada/obj/pick.c");
	}