#include <mudlib.h>

void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 2 );
	ob->set_name( "boarman", "野猪人" );
        ob->set_short( "野猪人" );
	ob->set_long(
		"这个....人有著野猪的头和人类的身体，但是长相实在比半兽人丑，你\n"
		"看了它的脸之後，忽然觉得半兽人并不如一般人心目中丑陋。\n"
	);
	ob->set( "gender", "male" );
	ob->set_perm_stat( "str", 4 );
	ob->set_perm_stat( "con", 3 );
	ob->set( "max_hp", 50 );
	ob->set( "hit_points", 50 );
	ob->set_skill( "blunt", 20 );
	ob->set( "natural_armor_class", 10 );
	ob->set( "wealth/silver", 10 );
	ob->wield_weapon("/d/noden/recamp/obj/club");
}
