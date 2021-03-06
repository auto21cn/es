//#pragma save_binary

#include <mudlib.h>
#include <ansi.h>

inherit DAEMON;

int cmd_shout(string str)
{
	int i, tp,woman;
	object me, *urs;
	string name, c_name, verb, str1, str2, msg, msg_me, color,c_you;

	me = this_player();
	urs = users();
	urs -= ({ me });
	
	name = capitalize((string)me->query("name"));
	c_name = (string)me->query("c_name");
	c_you = ((string)me->query("gender")=="female"? "你":"你") ;

	if( me->query_level() < 3 ) return notify_fail( 
		"很抱歉，为了避免有人蓄意骚扰，等级三以下的玩家不准使用 shout 指令。\n");

	if ( me->query_temp("shoutter")) return notify_fail ( 
		"你刚刚才用力的尖叫过，嗯 .. 还是不要「叫」得太频繁 ..\n");

	if( !str || str=="" ) return notify_fail( 
		"你要叫什麽？\n");

	tp = (int)me->query("talk_points");

	if( !wizardp(me) && tp < 50 ) return notify_fail( 
		"你已经叫得太出力，现已无力再喊，休息下吧。\n");

	str = replace_string(str,ESC,"");
	if( msg = me->query_env("C_MSHOUT") ) {
		if( sscanf(msg, "%s$N%s", str1, str2) == 2 ) {
			msg = sprintf("%s%s(%s)%s : ",
				  str1,c_name,name,str2);
//			msg_me = sprintf("%s%s%s : ",str1,c_you,str2 );
		} else {
			msg = sprintf("%s(%s)%s : ",c_name,name,msg);
//			msg_me = sprintf("%s%s : ",c_you,msg);
		}
	} else {
		msg = sprintf("%s(%s)喊道 : ",c_name,name);
//		msg_me = sprintf("%s喊道 : ",c_you);
	}
	
	color = me->getenv("ENV_COLOR");
	if( !color ) color = "HIR";
	for( i= sizeof(urs)-1 ; i>=0; i-- ) {
		if( !environment(urs[i]) ) continue; 
		urs[i]->quick_message(sprintf("%s%s\n",set_color(
			 msg , color, urs[i]),str) );
	}
	printf("%s%s\n",set_color(c_you+"喊道 : ", color),str);

	if( !wizardp(me) ) {
		me->add( "talk_points", -50 );
 		me->set_temp("shoutter",1);
		call_out("recover_shout",1,me);
	}

	return 1;
}

void recover_shout(object me)
{
	if ( !me ) return ;
	me->delete_temp("shoutter");
	return;
}
int help()
{
   write(@HELP
使用格式: shout <信息>

属于广播性质，但级别3以下的玩家不能使用.
同时使用时消耗20点谈话值，为0时将无法使用.
HELP
);
   return 1;
}