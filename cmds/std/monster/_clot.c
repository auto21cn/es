#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;

int cmd_clot(string arg)
{
	object dest;
	int skill;
	mixed bleed;

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "你要替谁止血？\n");

	if( !living(dest) ) return notify_fail("那个「东西」不会流血。\n");

//	if( dest==this_player() ) return notify_fail( chinese_mode?
//		"你不能对自己施行急救。\n": "You can't aid yourself.\n" );

	if( dest->query("ghost") ) return notify_fail( 
		"太迟了 .... "+dest->query("c_name")+"已经死了。\n");

	if( dest->query_temp("clotted") ) return notify_fail(
		dest->query("c_name") + "的伤口已经止血处理过了。\n");

	if( !(bleed = dest->query("conditions/bleeding")) )
		return notify_fail(
			dest->query("c_name") + "并没有失血的情形。\n");

	skill = (int)this_player()->query_skill( "clotting");
	if( !skill ) return notify_fail("你并没有学过止血的技能。\n");

	write(
		"你替" + dest->query("c_name") + "的伤口进行止血 ....\n");
	tell_object( dest, 
		this_player()->query("c_name") + "替你的伤口止血 .... 你觉得好多了！\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name") + "替" + dest->query("c_name") + "的伤口止血。\n",
		({ this_player(), dest }) );
	if( dest!=this_player() )
		this_player()->add( "alignment", 25 );
	if( skill/2 + random(skill/2) > bleed[1] * bleed[2] ) {
		this_player()->receive_experience( skill );
		(CONDITION_PREFIX + "bleeding")->remove_effect( dest );
	} else {
		bleed[2] /= 2;
		dest->set( "conditions/bleeding", bleed );
		this_player()->receive_experience( skill/2 );
	}
	dest->set_temp("clotted", 1 );
	call_out( "remove_clotted", 120, dest );
    return 1;
}

void remove_clotted(object player)
{
	if( player ) player->set_temp("clotted", 0);
}

int help()
{
    write(can_read_chinese()?
    @C_HELP
指令格式: clot <某人>

这个指令让你替某个人物( 或 NPC )的伤口止血，有关止血的细节与限制请参
考 help clotting。
C_HELP
    :@HELP
Usage: clot <someone>

This command enables you to clot another player or NPC's bleeding wounds.
For more information about clotting, see help clotting.
HELP
	);
    return 1;
}
