#include <mobs.h>
#include <races.h>

inherit RACE_DAEMON;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(10);
	set_name( "summoned monster", "召唤兽" );
	add ("id", ({ "summon", "monster", }) );
	set_short( "a summoned monster", "召唤兽" );
	set_long( @C_LONG
拉修帝用魔法呼叫出的怪物，完全为保护主人而活。
C_LONG
	);
    set( "unit", "只" );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 22 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 15 );
	set ("max_hp", 280);
	set ("hit_points", 280);
	set_natural_weapon( 27, 14, 25 );
	set_natural_armor( 63, 25 );
    set ("weight", 900);
    set ("exp_reward",1500 );
    set ("speed", 20 );
    set ("moving", "@@query_moving" );
    set ("special_defense", ([ "all" : 10, ]) );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical" : 50, ]) );
    set_skill("dodge",50);
    set_c_verbs( ({ "%s狂抓%s", "%s猛撞%s", "%s乱踢%s", "%s死咬%s", }) );
    set_c_limbs( ({ "头", "身体", "脚", }) );
}

int query_moving()
{
	if( present( "rashudi", environment(this_object()) ) ) return 0;
	return 1;
}

int catch_huntee( object who )
{
    if( !present( "rashudi", environment(this_object()) ) ) return 0;
    tell_room( environment(this_object()), 
      "召唤兽很不屑的向"+who->query("c_name")+
      "说: 你还敢进来，想攻击我的主人吗? 别梦想了，死吧!\n"
    ,  ({ this_object(), who }) );
    tell_object( who,   "召唤兽很不屑的向你说: 你还敢进来，想攻击我的主人吗? 别梦想了，死吧!\n"
    );
    return 1;
}
