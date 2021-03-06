#include "saulin_monk.c"

void create()
{
	::create();
	set_level(5);
	set_name( "gin ping", "静平" );
	add ("id", ({ "gin", "ping","monk" }) );
	set_short( "静平" );
	set_long(
"静平年方十二，到少林刚学会一点基本的拳脚功\夫，最怕偷懒时被抓到。\n"
	);
    set( "alignment",10);
    set( "gender", "male" );
    set( "race", "imp" );
    set( "unit", "位" );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 7 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 8);
	set_skill("unarmed",100);
	set_skill("dodge",35);
	set("aim_difficulty", ([ "critical":5, "vascular":4, ]) );
	set("max_hp", 120);
	set("max_fp", 25);
	set("hit_points", 120);
	set("force_effect", 2);
	set("force_points", 25);
	set("attack_skill",FIST"long_fist");
	set("defense_type","dodge");    
	set("wealth/gold", 4);
	set_natural_weapon( 12, 3, 7 );
	set_natural_armor( 30, 12 );
        set("weight", 300);
#include <replace_mob.h>
}
