#include <mudlib.h>
inherit DAEMON;
int cmd_skilllevel()
{
	object owner;
	owner = this_player();
tell_object(owner,
"姓名 : "+owner->query("c_name")+"\n"
"\t技能\t\t等级\t\t经验\n"
"\t背刺\t\t"+owner->query("thief_level/backstab")+"\t\t"+owner->query("thief_exp/backstab")+"\n"
"\t射飞刀\t\t"+owner->query("thief_level/throw-dagger")+"\t\t"+owner->query("thief_exp/throw-dagger")+"\n" );
// "\t偷窃\t\t"+owner->query("thief_level/steal")+"\t\t"+owner->query("thief_exp/steal")+"\n" );
	return 1;
}

int help()
{
	write(@HELP
指令格式 : skilllevel
    这个指令让你知道目前你各种技能的等级。
HELP
	);
}

