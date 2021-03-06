#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "Death scythe", "死神镰刀" );
	add ("id", ({ "scythe", }) );
	set_short( "死神镰刀" );
	set_long( @LONG
一把死神最心爱的兵器，正在为得到自由而高兴的飞舞著。
LONG
	);
   set( "race", "undead" );
	set( "alignment", -1000 );
    set( "unit", "把" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 20 );
	set ("chat_chance", 5);
	set ("chat_output", ({
	  "死神镰刀说: 我自由了，我自由了!\n", }) 
	);
	set ("max_hp", 1200);
	set ("hit_points", 1200);
	set ("persuing", 1);
   set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("aim_difficulty", ([ "critical" : 100, ]) );
	set_natural_weapon( 75, 40, 80 );
	set_natural_armor( 110, 50 );
    set ("weight", 150);
    set ("exp_reward", 32767 );
    set ("special_defense", 
         ([ "all":50, "none" : 25 ]) );
    set_skill("dodge",85);
    set_c_verbs( ({ "%s直削%s", "%s横劈%s", "%s横扫%s"}) );
    set_c_limbs( ({ "刀刃", "把手", "刀背", }) );
    set( "alt_corpse", MOYADA"obj/death_scythe" );
    set( "c_death_msg", "%s无力的飞舞几下，掉到地上不动了!\n");
}
