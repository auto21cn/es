// /d/abyss/hell/monster/horseface.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(15);
	set_name("horseface", "马面将军");
	set_short("General Horseface", "马面将军");
	set_long(
		"You se a huge giant with horse face.\n",
		"马面将军的脸虽然长得像马，但是他的剑术足以使胆敢取笑他长相的人\n"
		"一辈子笑不出来。\n"
	);
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "block", 100 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "kar", 20 );

	set( "gender", "male" );
	set( "alignment", 1000 );
	set( "special_defense", ([ "all": 40 ]) );
	set( "exp_reward", 1 );

	ob1 = new( "/d/abyss/hell/obj/bin_armor" );
	ob1->move( this_object() );
	equip_armor( ob1 );
	ob2 = new( "/d/abyss/hell/obj/bin_shield" );
	ob2->move( this_object() );
	equip_armor( ob2 );
	ob3 = new( "/d/abyss/hell/obj/bin_sword" );
	ob3->move( this_object() );
	wield_weapon( ob3 );
}
