//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int help();
int bribe_work(object me, object victim, int charm);
int cmd_bribe()
{
	int skill, tp_cost, delay, num, charm, num1, time;
	object me, victim;
	
	me = this_player();
    if( me->query_level() < 5 )
        return notify_fail("你到底想干嘛啦?\n");
    if( me->query_temp("bribe_busy") )
    	return notify_fail("同时贿赂两个人是不可能的。\n");

	victim = me->query_attacker();
	
switch( me->query("race") ) {
	case "human" : 	charm == 3;		break;
	case "elf"        :  charm == 4;		break;
	case "dwarf":  charm == 2;		break;
	case "orc"    : 	charm == 1;		break;
	case "gnome"     : 	charm == 3;		break;
	case "halfling"       : 	charm == 4;		break;
	case "lizardman" : 	charm == 1;		break;
	case "imp"   : 	charm == 3;		break;
	case "daemon"     :  charm == 4;		break;
	case "vampire"      : 	charm == 4;		break;
	case "beholder" :  charm == 5;             break;
	case "drow" :  charm == 3;             break;
	default          :	charm == 2;
		}
	

	if( !victim ) return notify_fail("你没在战斗中，找不到对手在哪里!\n");
	if( !skill = (int)me->query_skill("polemic") )
		return notify_fail( "你没有学过辩术，口才也不好，怎麽去贿赂别人呢 !!!\n");
        if( victim->query("prevent_give_money") )
                return notify_fail("这家伙看来是不能贿赂的!\n");
        num1 = (victim->query_level()+26)/me->query_level();
	
	time = victim->query_temp("bribe_time") ; 
	num = 5*(1 + time*time)*num1;
	tp_cost = 65 - (skill / 6) - (5 * charm);
	if( !tp_cost || (int)me->query("talk_points") < (tp_cost + 1) )
		return notify_fail("你讲了太多话了，现在一句话都说不出来！\n");
	if (me->query("wealth/gold")<num+1)
	        return notify_fail("贿赂最好用金币，但你的金币不够！\n");
	else
		me->add("talk_points", -tp_cost );

	tell_object(me, set_color("你鼓起如簧之舌，双手捧起一把金币，开始贿赂你的对手 ! \n", "HIC",me) );
	tell_object(victim, set_color("你看到"+me->query("c_name")+"带著一脸谄媚的笑容走到你面前试图贿赂你! \n", "HIC",victim) ); 
        tell_room( environment(me),
                me->query("c_name")+"满脸陪笑的走到"+
                victim->query("c_name")+"的面前试图贿赂他。\n" ,({ me, victim }) );
        delay = 6 - skill/10 - (charm+1)/2;  
        if( delay < 0 ) delay = 1;
        else delay = 2;
               
	
	me->set_temp("bribe_busy",1);
	call_out("bribe_work", delay, me, victim, charm);
	return 1;
}

int bribe_work(object me, object victim, int charm)
{
	int my_kar,vic_int,level,vic_level,chance,skill,num,num1,time;
        string gold;
	
	me->delete_temp("bribe_busy");
	skill = me->query_skill("polemic");
	my_kar = me->query_stat("karma");
	vic_int = victim->query_stat("int");
        time = victim->query_temp("bribe_time");
        level = me->query_level();
        vic_level = victim->query_level();
	chance = my_kar-vic_int+level-2*vic_level;
	num1 = (victim->query_level()+26)/me->query_level();
	num = 5*(1 + time*time)*num1;
	if (me->query("wealth/gold")<num+1) 
	                return notify_fail("你以为你很聪明吗??别傻了！\n");
	if ( ! me->query_attackers() || !victim || victim->query("hit_points") < 1) {
		tell_object(me,"你的战斗结束了，不要浪费钱了! \n");
		return 1;
	}
	if( skill+chance+random(3*charm)+random(skill) < vic_int+vic_level ) {
		tell_object(me,set_color("你的敌人很高兴的接过你手上的金币，然後继续打你!\n", "HIG",me) );
		tell_object(victim,set_color("你摇头叹道: 可怜的疯子，临死钱还送钱给我! \n", "HIC",victim) );
	        tell_room( environment(me),"\n"+
		victim->query("c_name")+"摇头叹道: 可怜的疯子，临死钱还送钱给我! \n\n" ,
	        ({ me, victim }) );
		me->add("wealth/gold",-num);
		victim->add("wealth/gold",num);
		return 1;
	}

        victim->remove_attacker(me);
        me->remove_attacker(victim);
//        me->cease_all_attacks();
        me->add("wealth/gold",-num);
	victim->add("wealth/gold",num);
	victim->add_temp("bribe_time",1);
	tell_object( me, set_color( 
		"你成功的说服敌人，用一些金币换来短暂的和平....\n", "HIY",me) );
		
	tell_object(victim, set_color( 
		me->query("c_name")+"给你一大把金币，你看的眼花撩乱，丧失了50%的战斗意志。\n", "HIM",victim));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"拿出一大把金币塞到"+
		victim->query("c_name")+"的身上，使得他停止对"+me->query("c_name")+"的攻击。\n\n" ,
		({ me, victim }) );
                return 1;
}
int help()
{
   write(
@C_HELP
指令格式: bribe 
   
这个指令让你有能力在战斗时使用金币去贿赂敌人，并使其放弃对
你的敌意。成功的机率与花费的金币数目与使用者本身的辩术有关
同时也与敌人的智力有关，若施术成功则可免去一场不必要的战争
，若失败则你将损失一笔钱。
如果该敌人先前曾接受你的贿赂，想再成功的贿赂则需要付出比上
更多的金钱。
C_HELP
   );
   return 1;
}   
