#include "../dgnisld.h"

inherit WEAPON;

void create()
{
	set_name("Dragon Killer", "杀龙剑");
	add ("id",({ "sword","dragon killer","longblade", }) );
	set_short("a Dragon killer", "杀龙剑");
	set_long(
	    "A long sword named \"Dragon Killer\". It can cause much damage\n" 
	"to dragons, dinosaurs as same as its name. But it is a normal long\n"
	"blade to other animals.\n",
	    "一把名为龙之终结者之剑，正如其名，它对龙、恐龙都有很大的杀伤力\n"
	"。但对於其他种类，它只是一把普通的长剑。\n"
	);
	
	set( "weapon_class", 10 );
	set( "type", "longblade" );
	set( "min_damage", 15 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "value", ({ 10, "gold" }) );
	set( "unit", "把" );
}
