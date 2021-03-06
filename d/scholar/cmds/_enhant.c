//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_GONFU_DIR "/d/scholar/gonfus/"

inherit DAEMON;

int help();

string *gonfus = ({ "force-heal", "couples_sword", "mar_short", "booyi",
                    "tanlo", "unknow", "han", "song", "tang" , "poem"});

int cmd_enhant(string str)
{
/*
        string *gonfus = ({ "force-heal", "couples_sword", "mar_short",
                            "booyi", "tanlo", "unknow", "han", "song",
                            "tang" , "poem"});
*/
        int level;
        object me, code;

        if( !str ) return help();
        me = this_player();

        if( str == "stop" ) {
                write( 
                        "你停止运用任何武功\。\n");
                me->delete("attack_skill");
                me->delete("defense_skill");
                return 1;
        }

        if( member_array(str, gonfus) == -1 )
                return notify_fail("疑! 这是那一种功\夫 ? \n");

        if( (int)me->query("stop_attack")>0 )
                return notify_fail (
                        "( 你上一个动作还没有完成，无法施展招式。 )\n");

        if( me->query("gonfu_busy") || me->query_temp("gonfu_busy") )
        return notify_fail("你目前正运功\所以无法另外运用其它武功\。\n");

        if( me->query_temp("stop_enhant") || me->query("stop_enhant") )
                return notify_fail("你正准备使用招式时，竟然发现你突然功\力全失了。\n");
        
        if( undefinedp(level=(int)me->query("scholar_gonfu/"+str)) )
                return notify_fail("疑! 你会这种功\夫 ? \n");

        code = find_object_or_load(SCHOLAR_GONFU_DIR+str);
        if( !code )
                return notify_fail("没有这种功\夫! 请通知巫师或用 bug 指令报告招式名称。\n");

        code->enhant(me, level);
        return 1;
}

int help()
{
                write( @C_HELP
指令格式: enhant <招式名称>

这个指令让你用来施展招式。你可以用 gonfus 指令看你目前已经学会的招式列表。
C_HELP
                );
    return 1;
}
