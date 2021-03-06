//#pragma save_binary

/*
// Author (??)
// Help added by Brian (1/28/92)
// Converted to mudlib 0.9.0 by Mobydick on 9/19/92
// Kill monster option added by Watcher on 2/19/93
// Watcher added vision check, 4/13/93

// The MudOS mudlib permits player killing by default. It is not hard to
// modify the mudlib to prevent player killing, or permit it only in special
// rooms such as arenas. Instructions for doing this are found in the file
// /doc/mudlib/player_killing.
// If you prevent player_killing you should probably prevent players from
// stealing from one another also, since fights start when the victim detetcts
// a theft.
*/

#include <mudlib.h>

inherit DAEMON;

// More fun. - Annihilator 12-08-93

string *start_fight = ({
	"%s喝道: 可恶的%s，看招！\n",
	"%s喝道: 该死的%s，下地狱去吧！\n",
	"%s喝道: 纳命来，%s！\n",
	"%s喝道: 去死吧 !! %s !!\n"
});

int help();
string get_monster();

int cmd_kill(string str)
{
	object victim, venv, me;
	int i;

	if( str == "monster" ) str = get_monster();
	if( !str || str == "" ) return help();

	me = this_player();
	if( (int)me->query("hit_points")<=0 )
		return notify_fail("很抱歉，你已经死了。\n");

	str = lower_case(str);
	venv = environment(me);
	if( !venv )
		return notify_fail("你不能在一片虚无当中攻击别人。\n");
 
	if( !me->query("vision") )
		return notify_fail("攻击谁？你什麽也看不见！\n");
 
	victim = present(str, venv);
	if( !victim || !visible(victim, me) )
		return notify_fail("这里没有你想攻击的对象。\n");

	if( !living(victim) )
		return notify_fail("看清楚，那不是值得攻击的对象。\n");

	if ( victim->query("no_attack") ) {
		if( !member_group((string)me->query("name"), "admin") )
		return notify_fail("别轻举妄动，这家伙你不能杀就是不能杀。\n");
	}
	if( (int)victim->query("ghost")==1 )
		return notify_fail("这个可怜虫已经死了，你还想怎样？\n");

	if( victim == me )
		return notify_fail("杀你自己？你不会拼 suicide 吗？\n");
 
	if( victim->query("linkdead") )
		return notify_fail("你不能趁人家断线的时候干这种事！\n");
 
 	if ( victim->query("user") ) {
	 	if( !member_group((string)me->query("name"), "admin") &&
 			(victim->query_level()<5 || me->query_level()<5) )
 		return notify_fail("在东方故事中五级以下的玩家不准 PK 和 PK 别人。\n");
	}
	i = me->kill_ob(victim);
	if( i==0 )
		write( "对！加油！加油！加油！\n");
	else {
		i = random( sizeof(start_fight) );
		write( 
			sprintf( start_fight[i],"你", victim->query("c_name") ));
		tell_room( environment(me), 
			sprintf( start_fight[i],
				me->query("c_name"), victim->query("c_name") ) ,
			me );
	}

	victim->set_heart_beat(1) ;
	return 1 ;
}

string get_monster()
{
	mixed *env;
 
	env = all_inventory( environment(this_player()) );
	if( !env || !sizeof(env) )  return 0;
 
	env = filter_array(env, "filter_npc", this_object());
	if( !env || !sizeof(env) )  return 0;

	return (string)env[0]->query("name");
}
 
int filter_npc(object obj)
{
	return (int)obj->query("npc");
}
 
int help()
{
		write(@HELP
指令格式: kill <怪物名称>

杀npc或玩家。当开始后将无法取消指令，除非有一方死亡。
此外npc会记仇，有些甚至会追杀你。。
HELP
		);
	return 1;
}
/* EOF */
