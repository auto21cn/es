//#pragma save_binary
// summon.
// This command lets a wizard move a player to him.
// It should be used ONLY to rescue trapped players. Other use constitutes
// cheating and may be a banishment offense.
// It does not work on fellow wizards.
// Written by Mobydick, 11-19-92
// him->objective() fix supplied by Geolin@Pyrosphere
// and included by Pallando 93-06-06

#include <mudlib.h>
#include <move.h>

inherit DAEMON ;

int help() ;

int cmd_summon (string name) {

	object player,env ;
	int res ;

	if (!name) {
		return help() ;
	}
	player = find_player(name) ;
	if (!player) {
		notify_fail ("没有叫做这个名字的人.\n") ;
		return 0 ;
	}
	if (wizardp(player)) {
		notify_fail("你不能召唤其他巫师，用「请」的比较好吧 .\n") ;
		return 0 ;
	}
	env = environment(player) ;
	res = player->move(environment(this_player())) ;
	if (res==MOVE_OK) {
		write ("你召唤 "+capitalize(name)+" 到你这里.\n") ;
		tell_room(env,(string)this_player()->query("c_name") +
		          "召唤"+name+"到他身边.\n");
		tell_object(player,(string)this_player()->query("c_name")+
			"召唤你到他身边 !\n");
		return 1 ;
	}
	write ("召唤失败 !\n") ;
	return 1 ;
}

int help() {
	write ("Usage: summon <player>\n\n"+
"This command will allow you to bring a player to your environment. It\n"+
"should be used ONLY to rescue players trapped by errors in the\n"+
"MUD. Other uses are illegal and may be a reason for banishment. Summoning\n"+
"has no effect on wizards. They should \"goto\" you instead.\n") ;
	return 1 ;
}
