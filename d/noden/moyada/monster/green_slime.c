#include "../moyada.h"
inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(5);
	set_name( "green slime", "绿色史莱姆" );
	add ("id", ({ "slime", }) );
	set_short( "绿色史莱姆" );
	set_long( @LONG
绿色的软体怪，身体黏黏答答的，怪恶心的。
LONG
	);
   set( "race", "undead" );
	set( "alignment", -100 );
    set( "unit", "只" );
	set_perm_stat( "dex", 3 );
	set_perm_stat( "str", 2 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 3 );
	set_perm_stat( "piety", 2 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 140);
	set ("hit_points", 140);
	set_natural_weapon( 13, 6, 9 );
	set_natural_armor( 100, 9 );
	set ("time_to_heal", 6);
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("special_defense",
	    ([ "all" : 30, "cold" : -50, ]) );
    set ("weight", 100);
    set ("exp_reward", 370);
    set ("chat_chance",5);
    set ("chat_output", ({
      "绿色史莱姆蠕动一下，爬过食物残渣并向你移动过来。\n"
    }) );
    set_c_verbs( ({ "%s蠕动到%s身上", "%s扑到%s脸上" }) );
    set_c_limbs( ({ "身体"  }) );
    set( "c_death_msg", "%s停止蠕动，死了.....\n" );
}
