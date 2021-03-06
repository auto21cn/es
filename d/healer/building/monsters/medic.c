#include <mudlib.h>

inherit "/std/seller";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Medic Wang", "王药师" );
	add( "id", ({ "medic", "wang" }) );
	set_short( "Medic Wang", "王药师" );
	set_long(
		"Medic Wang has just come back from a long trip in the mountains\n"
		"for gathering rare herbs and record the places they grow.\n",
		"王药师刚从深山中采药回来，他是行医者公认的草药权威，几乎\n"
		"所有珍贵药草生长的地点都是他发现的。你可以向他购买一些配\n"
		"药所需的用具或一些常见的药材，问他有关草药(herb)的事情。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "dex", 30 );
	set_skill( "dodge", 100 );
	set_skill( "dagger", 100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "weakest" );
	set( "max_hp", 600 );
	set( "hit_points", 600 );
	set_natural_armor( 110, 50 );
	set_natural_weapon( 50, 25, 36 );
	set( "special_defense", ([ "all": 50,"none":60]) );
	set( "aim_difficulty",([ "weakest":25,"vascular":30 ]) );
	set( "alignment", 1500 );
	set( "inquiry", ([ "herb":"@@show_menu"]) );
	set_inventory( ({
		({ "/obj/bowl", 20, 20 }),
		({ "/d/healer/reagent/yellow_mushroom", 30, 30 }),
		({ "/d/healer/reagent/swamp_berry", 30, 30 }),
		({ "/d/healer/reagent/ginseng", 5, 5 }),
	}) );
}
