#include <mudlib.h>

inherit MONSTER;
int wait_state;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(17);
	set_name( "Musashi", "武藏" );
	add( "id", ({ "travelling samurai", "samurai" }) );
   set_short( "修行武士武藏" );
	set_long(
		"武藏是从一个遥远的东方国家，叫做日本国来的修行武士，他正\n"
		"在寻求身为武士所依循的正道。\n"
	);
	set( "gender", "human" );
	set( "gender", "male" );
	set( "alignment", 600 );
    set_natural_armor( 20, 30 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage", 5 );
	set( "natural_max_damage", 5 );
	set( "wealth/gold", 30 );
	set( "tactic", "melee" );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "pie", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	set_skill( "tactic", 80 );

	ob1 = new( "/d/noden/bluesand/item/katana" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/bluesand/item/yoroi" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/bluesand/item/kabuto" );
	ob3->move( this_object() );
	equip_armor( ob3 );
}

int my_tactic()
{
	object *victim;

	if( !(victim = query_attackers()) ) return 0;
	if( wait_state ) {
		if( --wait_state ) {
                    tell_room( environment(),
                           "武藏敛气凝神，不知道想干什麽 ....\n",
				this_object() );
			return 1;
		} else {
                    tell_object( victim[0],
				"武藏大喝: 好机会！\n你见到武藏以闪电般的速度冲向你毫无防备的地方，一阵随之而来的剧痛\n"
                            "使你几乎无法感觉出自己被击中的部位。\n" );
                    tell_room( environment(this_object()),
				"武藏大喝: 好机会！\n"
"只见闪电般的刀光在你面前一闪，"+victim[0]->query("c_name")+"的身上已经多了一个又深又长的伤口！\n" ,
				({ this_object(), victim[0] }) );
			victim[0]->receive_damage( (int)query("max_damage1") * 3 );
			return 1;
		}
	}
	if( random(20)<5 ) {
		wait_state = 2 + random(3);
		return 0;
	}
}
