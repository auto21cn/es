#include "../saulin_temple.h" 

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(16);
	set_name( "barbarian fighter", "野蛮人战士" );
	add( "id", ({ "fighter" }) );
	set_short( "野蛮人战士" );
	set_long(@C_LONG
这个野蛮人身高两公尺半，看它一身的石头防具你就知道它的力量多大了。
它是野蛮人的伟大战士，住在东方的深山中。它听人说起少林的武功\很厉 
害，所以决定亲自来看看。
C_LONG
                );
	set_perm_stat( "str", 30 );
	set_perm_stat( "kar", 17 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "int", 14 );
	set_skill( "bo", 80 );

	set_natural_armor( 72, 25 );
	set_natural_weapon( 0, 10, 10 );
	set( "time_to_heal", 2 );

        set("special_defense", ([ "all":30, "none":10, "monk":10 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":30,
                                  "ganglion":40,"weakest":10, ]) );

	set( "max_hp", 900 );
	set( "hit_points", 900 );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "wealth/silver", 720 );
	set( "pursuing", 1 );
        set ("exp_reward", 14000);

	wield_weapon(SAULIN_OBJ"stone_club1");
	equip_armor(SAULIN_OBJ"stone_helmet");
	equip_armor(SAULIN_OBJ"stone_leggings");
}
