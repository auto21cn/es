//#pragma save_binary

// Estimate command
// By Annihilator@Eastern.Stories

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_consider(string arg)
{
	int my_power, dest_power, diff;
	int alignment, ethics_skill;
	object dest, me;

	if( this_player()->query("stop_attack") > 0 )
		return notify_fail( 
			"( 你还没有完成上一个动作，无法评估任何怪物。 )\n");

	if( !arg || arg=="" )
		return notify_fail( 
			"指令格式: consider <怪物名>\n");

	if( !dest= present( arg, environment(this_player()) ) )
		return notify_fail(
			"这里没有这种怪物。\n");

	me = this_player();
	me->calc_weapon_class();
	my_power = ((int)me->query("weapon_class1") - (int)dest->query_stat("dex"))*3 + 50;
	if( my_power < 5 ) my_power = 5;
	if( my_power > 95 ) my_power = 95;
	my_power *= (((int)me->query("min_damage1") + (int)me->query("max_damage1"))/2
		- (int)dest->query("defense_bonus"));
		
	dest->calc_weapon_class();
	dest_power = ((int)dest->query("weapon_class1") - (int)me->query_stat("dex"))*3 + 50;
	if( dest_power < 5 ) dest_power = 5;
	if( dest_power > 95 ) dest_power = 95;
	dest_power *= (((int)dest->query("min_damage1") + (int)dest->query("max_damage1"))/2
		- (int)me->query("defense_bonus"));
	
	// Make bias with skill	
	my_power += 1000 * random(100-(int)me->query_skill("consider")) / 100;
	dest_power -= 1000 * random(100-(int)me->query_skill("consider")) / 100;

	diff = my_power - dest_power;
	if( diff < -3000 ) write( 
	    "我想一定是某位巫师在戏弄你，就算十个19级的player也撑不住他一下攻击。\n");
	else if( diff < -2000 ) write( 
		"别傻了，你大概有一半以上的机会在一回合内被杀。\n");
	else if( diff < -1000 ) write( 
		"如果你穿著全套最好的盔甲，手持稀世宝刀，外带一大堆恢复药剂，也许\....\n");
	else if( diff < -500 ) write( 
		"你赢的机会很低，对方的各项能力都比你强很多。\n");
	else if( diff < -200 ) write( 
		"这种对手以你目前的能力而言，似乎有点勉强。\n");
	else if( diff < -50 ) write( 
		"如果你的运气不错，要打赢这样的敌人并不是很难。\n");
	else if( diff < 50 ) write(
		"对方和你是半斤八两，旗鼓相当。\n");
	else if( diff < 200 ) write( 
		"只要你不出什麽纰漏，这样的敌人很好对付。\n");
	else if( diff < 500 ) write( 
		"对方的各种能力都比不上你，不必担心。\n");
	else if( diff < 1000 ) write(
		"这种敌人对你而言，完全不构成任何威胁。\n");
	else if( diff < 2000 ) write(
		"我相信你可以在三回合内把这家伙干掉。\n");
	else write( 
		"老实说，欺负这种弱小敌人实在是浪费时间。\n");

	if( ethics_skill =me->query_skill("ethics") ) {
		alignment = (int)dest->query("alignment") 
			- random((100-ethics_skill)*20) + (100-ethics_skill) * 10;
		write(
			"你认为这是个「" + STATS_D->alignment_string(alignment) + "」之流的对手。\n");
	}
	return 1;
}

int help()
{
	write( @HELP
使用格式: consider <生物名字>

这个指令将判断生物的强弱，准确程度受技能影响.
如果你的评估技能等级高，会大大提高评估准确度.
HELP
	);
	return 1;
}
