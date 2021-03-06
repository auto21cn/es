//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int cmd_ask(string str)
{
	string mon_name, subject, func;
	object mon_obj;
	mapping cmd_map;

	if (!str)
		return notify_fail(
			"要问非玩者人物问题，请用 \"ask <谁> about <关键字>\"。\n");

	if (sscanf(str, "%s about %s", mon_name, subject) != 2)
		return notify_fail( 
			"要问非玩者人物问题，请用 \"ask <谁> about <关键字>\"。\n");

	mon_name = lower_case(mon_name);

	if( !(mon_obj= present(mon_name, environment(this_player()))) )
		return notify_fail( 
			"你要问的对象并不在这里。\n");

	if (mon_obj->query("user")) {
		write( 
			"你向"+ mon_obj->query("c_name") + "询问有关 "+subject+" 的事。\n");

		tell_object( mon_obj,
			this_player()->query("c_name")+"问你: 知不知道有关 "+subject+" 的消息？\n");
		return 1 ;
	}

	cmd_map = ([ ]);
	cmd_map = mon_obj->query("inquiry");

	if (sizeof(cmd_map)==0) {
		write( 
			mon_obj->query("c_name")+"对你的问题没有任何反应....。\n");
		return 1 ;
	}
	if( undefinedp(cmd_map[subject]) ) {
		tell_room(environment(this_player()), 
			this_player()-> query("c_name") + "向" + mon_obj->query("c_name")
			+ "打听有关 " + subject + " 的消息。\n",
			this_player() );
		tell_room( environment(this_player()), 
			mon_obj->query("c_name") + "摇摇头，说道: " + "我不知道....。\n" );
	} else {
		tell_room(environment(this_player()), 
			this_player()-> query("c_name") + "向" + mon_obj->query("c_name")
			+ "打听有关 " + subject + " 的消息。\n",
			this_player() );
		if( stringp(cmd_map[subject]) && sscanf( cmd_map[subject], "@@%s", func )==1 )
			call_other( mon_obj, func, this_player() );
		else {
			if( pointerp(cmd_map[subject]) )
				tell_room(environment(this_player()), 
					mon_obj->query("c_name") + "说道: " + cmd_map[subject][0] + "\n",
					mon_obj );
			else
				tell_room(environment(this_player()), 
					mon_obj->query("c_name") + "说道: " + cmd_map[subject] + "\n",
					mon_obj );
		}
	}
	return 1;
}
int help()
{
	write(@HELP
使用格式: ask <生物名> about <事物>

用于以npc交谈、解谜的标准指令.
不过有些场合仍要先用say或tell指令对npc说关键字才能触发情节.

HELP
);
	return 1;
}