// /d/abyss/hell/monster/bullhead.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(15);
	set_name("bullhead", "牛头将军");
	set_short("General Bullhead", "牛头将军");
	set_long(
		"You see a huge giant with bull's head. He looks as strong as his\n"
		"mighty battleaxe.\n",
		"牛头将军看起来又粗又壮，他站立的时候几乎有三公尺高，手中拿著一把\n"
		"刀刃比桌子还大的巨型战斧。\n"
	);
	set_skill( "axe", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "kar", 20 );

	set( "gender", "male" );
	set( "alignment", 1000 );
	set( "special_defense", ([ "all": 40 ]) );
	set( "exp_reawrd", 1 );

	ob1 = new( "/d/abyss/hell/obj/bin_armor" );
	ob1->move( this_object() );
	equip_armor( ob1 );
	ob2 = new( "/d/abyss/hell/obj/bin_axe" );
	ob2->move( this_object() );
	wield_weapon( ob2 );
}
