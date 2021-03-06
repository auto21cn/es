// Created by Kyoko.

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON ;

int gonfu_exists(string gonfu);

int help() ;

int cmd_enhant(string gonfu)
{
	int fp_cost, delay_time;
    object code;
    
	if( !gonfu ) return help();

	if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail (can_read_chinese()?
			"( 你上一个动作还没有完成，无法施展招式。 )\n":
			"( You are too busy to enhant a gonfu now. )\n"
		);
    if( this_player()->query_temp("no_enhant") ||
        this_player()->query("no_enhant") )
      return notify_fail( can_read_chinese() ?
        "你正准备使用招式时，竟然发现你突然忘记起手式了。\n" :
        "You forget how to enhant any gonfu!\n"
      );
    if( environment(this_player())->query_temp("no_enhant") ||
        environment(this_player())->query("no_enhant") )
      return notify_fail( can_read_chinese() ?
        "这里不能使用任何招式。\n" :
        "You can not enhant any gonfu here!\n"
      );
	if( !(this_player()->query("gonfus/"+gonfu)) )
	  return notify_fail( can_read_chinese()?
		"你不会这种\功\夫。\n":
		"You don't know such a gonfu.\n"
	  );
	code = GONFU_D->find_gonfu( gonfu );
	if( !code )
		return notify_fail( can_read_chinese()?
			"没有这种功夫 .... 请通知巫师或用 bug 指令报告招式名称。\n":
			"No such gonfu .... please tell a wizard or report bug.\n"
		);
	fp_cost = (int)code->query_fp_cost();
	delay_time = (int)code->query_delay_time();
	if( !fp_cost || (int)this_player()->query("force_points") < fp_cost )
		return notify_fail( can_read_chinese()?
			"你的内力不够！\n":
			"You don't have enough force points!\n"
		);
    if( (string)this_player()->query_temp("gonfu_now") == gonfu )
        return notify_fail( can_read_chinese()?
			"你已在施展这功\夫了！\n":
			"You have enhanting this gonfu!\n"
		);
    this_player()->set_temp("gonfu_now", gonfu);
    this_player()->set_temp("gonfu_delay_time", delay_time);
	if( code->enhant() )
	  this_player()->add("force_points", -fp_cost );
	return 1;
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
指令格式: enhant <招式名称>

这个指令让你用来施展招式。你可以用 gonfus 指令看你目前已经学会的招式列表。
C_HELP
		);
	else write ( @HELP
Usage:	enhant <gonfu name>

This command let you enhant gonfus. You can type "gonfus" to see the 
gonfus you have learned.
HELP
    );
    return 1;
}
