#include <../saulin_temple.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(13);
	set_name( "Ma gi", "铁锁银划 马纪" );
	add("id",({"gi","ma","Ma"}) );  
         set_short( "铁锁银划 马纪" );
	set_long(@C_LONG
马纪是少林的俗家弟子,擅常鞭法和判官笔,武林中称他为『铁锁银划』
他素来行侠仗义,此番回少林不知有何原因...
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
	set_skill( "whip",40);
        set_skill( "dodge", 80 );
	set_skill( "thrusting", 80 );
	set_skill( "two-weapon", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "gender", "male" );
	set( "alignment", 320 );
	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 25 );
	set( "natural_weapon_class1", 8 );
	set( "natural_weapon_class2", 8 );
	set( "natural_min_damage1", 9 );
	set( "natural_max_damage1", 16 );
	set( "natural_min_damage2", 2);
	set( "natural_max_damage2", 5 );
	set( "wealth/gold", 22 );
	ob1 = new( "/d/eastland/haiwei/obj/pen" );
	ob1->move(this_object());
	wield_weapon(ob1);
	ob2 = new( SAULIN_OBJ"rope" );
	ob2->move(this_object());
	wield_weapon2(ob2);
}
