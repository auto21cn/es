// The Void....
// This is used as a temporary storing place for wizards during sensitive
// operations, such as updating their environment. If the update fails,
// then the player is here instead of having a null environment.
// There is a difference between being in this room and being in the void,
// which is when your environment pointer is null
//  This is an old and headerless file.
// Most likely either from Lars, or a VERY early TMI hacker.
// Mobydick added the header years later (specifically, 8-31-93).

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "The Void", "一片虚无" );
	set_long(
		"You are in the void.\n"
		"There is nothingness everywhere and you cannot stand it!\n",
		"你现在身处一片虚无的空间，举目所及都是一片灰蒙蒙的阴影\n"
		"和空白。\n");
	set("light", 1);
}
