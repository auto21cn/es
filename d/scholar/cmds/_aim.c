//#pragma save_binary
#include <mudlib.h>
#define VALID_LOC ({ "ganglion", "weakest", "critical" })

inherit DAEMON;

int help();

int cmd_aim(string str)
{
	string loc;

	if( !str || str=="" ) {
		if( (loc= this_player()->query( "aiming_loc" )) ) {
			write("你现在设定战斗时瞄准: " + to_chinese(loc) + " ( " + loc + " )\n");
			return 1;
		}
		return help();
	}
	if( !this_player()->query_skill("anatomlogy") )
		return notify_fail("你并没有学过解剖学 ....。\n");
	if( member_array(str, VALID_LOC)==-1 ) return help();
	this_player()->set("aiming_loc", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write( @C_HELP
指令格式: aim <部位>

这个指令让你在战斗中尝试去打中敌人的某些特殊部位，这些部位一但打中，有可
能造成敌人各种损伤或是能力的降低，命中率视敌人的不同、瞄准的部位和你的解
剖学技能与所使用的武器而定。

你所能瞄准的部位有:

ganglion -     神经聚集的地方，击中後可以令敌人在几回合内无法攻击。
weakest -      敌人防御力最弱的部位，击中後可以使敌人受到你目前所能造成
               的最大伤害。
critical -     敌人的致命弱点，击中後使敌人的体力立即降到 1/3 以下，不过
               成功\机会不大。

C_HELP
	);
	return 1;
}
