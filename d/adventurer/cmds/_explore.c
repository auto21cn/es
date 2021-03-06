//#pragma save_binary

#include <mudlib.h>

#define MESSAGE ({"蹲下来开始检查路边的野花...\n","拿只放大镜对地面猛瞧...\n","在地上挖了好大一个洞然後跳进去...\n","趴在地上东张西望...\n","伸手擦了擦额头上的汗水...\n" })
inherit DAEMON;


int help();
int explore_work(object me,object env,int time);
int cmd_explore()
{
	int skill,tp_cost,sp_cost,hp_cost,time;
	object me, env;
	
	time = 5;
	me = this_player();
    if( me->query_attacker() )
        return notify_fail("你还在战斗喔，不要分心喔...\n");
    if( me->query_temp("explore_busy") )
    	return notify_fail("别闹了，你不是正在作吗。 \n");

	env = environment(me);
	
	if( !env ) return 0;
    if( !env->query("outside") )
        return notify_fail("这里好像没有什麽特别值得注意的自然物。 \n");	
	if( !skill = (int)me->query_skill("natural_history") )
		return notify_fail( "你没有学过博物学，不用浪费时间啦 !!!\n");
	tp_cost = 60 - skill/5 ;
	sp_cost = 15 - skill/10 ;
	hp_cost = 20 - skill/10 ;
	
	if( !tp_cost || (int)me->query("talk_points") < (tp_cost + 1) )
		return notify_fail("你太渴了，再不找点水来补充一下可不太好！\n");
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
	        return notify_fail("你精神力太差了，快点找地方休息吧！\n");
	if( !hp_cost || (int)me->query("hit_points") < (hp_cost + 1) )
	        return notify_fail("你就快驾鹤西归了，还想要干嘛啊！\n");
	                
	                
	else
		me->add("talk_points", -tp_cost );
		me->add("spell_points", -sp_cost );
		me->add("hit_points", -hp_cost );

	tell_object(me, set_color("你把袖子卷了起来，开始仔细的探索附近的一草一木 ! \n", "HIC",me) ); 
	
	me->set_temp("explore_busy",1);
	me->set_temp("block_command", 1 );
	me->set_temp("msg_stop_attack",
	         "( 你正於沉迷於探索大自然的乐趣之中！无法攻击... )\n" );
	call_out("explore_work", 5, me, env, time);
	return 1;
}

int explore_work(object me,object env,int time)
{
	int skill,my_kar,my_pie,num,chance,n,i,delay;
	object thing;
	skill = me->query_skill("natural_history");
	delay = 40 - skill/10 - me->query_stat("pie")/2 ;
	if ( time < delay ) {
	time = time + 5 ;
	i = random(4);
	tell_object( me, set_color(
	 "你"+MESSAGE[i] , "HIY", me) );
	tell_room( env,
	                "你看到"+ me->query("c_name")+MESSAGE[i],me );
	
	call_out("explore_work", 5, me, env, time, delay);
	return 1;
	}
        num = env->query("explore_time");
	my_kar = me->query_stat("karma");
	my_pie = me->query_stat("piety");
	chance = 57 - my_pie/2 - skill/4 - my_kar/2 + num*10 ;
	me->delete_temp("msg_stop_attack");
	me->delete_temp("block_command");
	me->delete_temp("explore_busy");
	
	if ( random(chance) >3 ) {
	tell_object( me, set_color( 
		"你找了半天，什麽都没有找到，你决定放弃搜索此处...\n", "HIY", me) );
	tell_room( env, 
		"你看到"+ me->query("c_name")+"从一堆草丛中钻出来，脸上满是失望的表情。\n\n" ,me );
                return 1;
                }
         switch( n= random(4) ) {
                    case 0: thing = new("/d/noden/monster/hornet");   break;
                    case 1: thing = new("/d/noden/monster/snake");   break;
                    case 2: thing = new("/d/adventurer/natural_history/unknow_tree");   break;
                    case 3: thing = new("/d/adventurer/natural_history/unknow_gem");   break;
                    default : break;
                    }
                  thing->move(environment(this_player()));
                  tell_object( me,
                      "皇天不负苦心人，你找到一"+thing->query("unit")+thing->query("c_name")+"...\n");
                  tell_room( env,
                      me->query("c_name")+"从草丛中找到了"+thing->query("unit")+thing->query("c_name")+"...\n",me);
                      
                  me->gain_experience(100);
                  if (n < 2) thing->kill_ob(this_player());
                  env->add("explore_time",1);
                  return 1;
}
int help()
{
write(
@C_LONG
指令格式: explore

这个指令能够使你运用所学的博物学(natural_history) 知识，从大自然中
寻找有用的自然物，而发现与否的机率与你的博物学，运气以及耐心都有关

C_LONG
);
    return 1;
}
