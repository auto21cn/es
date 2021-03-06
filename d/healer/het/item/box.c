// bag.c
// A simple bag.
// Originally written by Truilkan 92/04/20.
// Updated to mudlib 0.9 by Mobydick, 10-14-92.
// This bag cannot be closed or locked. For an example of a container which
// can be both closed and locked, see /obj/chest.c.

#include <mudlib.h>
inherit CONTAINER;

void create()
{
	::create();
	set_name("box", "药囊");
	set_short("a box", "药囊");
	set_c_open_long("这是一个普通的药囊，通常是用来装各种草药的。\n");
	set( "weight", 10);
	set( "weight_apply", 200 );
	set( "max_load", 200);
	set( "value", ({ 630, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}
