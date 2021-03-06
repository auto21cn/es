// chainmail.c
// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create()
{
	set_name( "chainmail", "锁子甲");
	add( "id", ({ "chain", "mail" }) );
	set_short( "a suit of chainmail", "锁子甲");
	set_long(
		"The mail mesh would cover your torso and upper arms.\n",
		"这套锁子甲可以保护你的身体和手臂。\n"
	);
	set( "type", "suit" );
	set( "armor_class", 6 );
	set( "weight", 150 );
	set( "value", ({ 30, "gold" }) );
}
