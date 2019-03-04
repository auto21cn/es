#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(6);
	set_name( "witch", "女巫" );
	set_short( "女巫" );
	set_long(
		"你看到一个又老又丑的女巫，她正像疯子般地盯著你怪笑....。\n"
	);
	set( "race", "gnome" );
	set( "gender", "female" );
	set_perm_stat( "int", 20 );
	set_skill( "wand", 60 );
	set( "alignment", -400 );
	set( "natural_armor_class", 25 );

	ob1 = new( "/d/noden/moyada/obj/wands/flamming_wand" );
	ob1->move( this_object() );
	wield_weapon( ob1 );
}
