#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron chain", "铁□" );
	add( "id", ({ "chain","whip" }) );
	set_short( "a iron chain", "铁□" );
	set_long(
		"You see an iron chain which used to lock felonries.\n",
		"这是一条长长的铁□，是公差们用来追拿犯人的武器。\n"
	);
	set( "unit", "条" );
	set( "weight", 70 );
	setup_weapon( "whip", 15, 8, 16 );
	set( "value", ({ 220, "silver" }) );
        set_c_verbs(({"%s甩向%s","%s砸向%s","%s挥向%s"}));
}
