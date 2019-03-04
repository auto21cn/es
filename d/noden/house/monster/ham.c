#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "ham", "火腿" );
   set_short( "火腿" );
	set_long(
		"你看到一根「匪夷所思」的火腿漂浮在空中....。\n"
	);
   set( "race", "undead" );
	set( "unit", "根" );
	set( "alignment", -100 );
	set( "natural_defense_bonus", 5 );
	set( "natural_weapon_class1", 2 );
	set( "natural_max_damage1", 2 );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set_skill( "dodge", 5 );
	set_c_verbs( ({ "%s扭著身子转了几圈，向%s冲去" }) );
	set_c_limbs( ({ "身体" }) );
}
