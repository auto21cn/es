#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "prisoner", "囚犯" );
	set_short( "囚犯" );
	set_long("一个看起来很可怜的家伙，他用茫然的眼神看著你。\n"
	);
	set( "unit", "名" );
	set( "gender", "male" );
	set( "race", "human" );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 18 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
}
