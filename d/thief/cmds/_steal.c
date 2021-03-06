//#pragma save_binary
#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })

#include <mudlib.h>

inherit DAEMON;
void remove_block(object me)
{
	me->delete_temp("block_command");
	return;
}

int steal_idle(object me,int succeed,object target,object item)
{
	mapping wealth;
	string type,*coins;
	int coin,i;
	me->set_temp("stealed",0);
	if ( !target || nullp(target) || (int)target->query("hit_points") < 1 ) {
		write("真不幸，那家伙已经死了 ...\n");
		return 1;
	}
	if ( !present(target,environment(me)) ) {
		write("你要偷的对象已经不在这里了 !!\n");
		return 1;
	}
	tell_object(me,set_color(
		sprintf("趁著%s不留意的时候，你小心的把第三只手伸向%s ...\n",
			target->query("c_name"),
			( !item ? target->query("c_name") : item->query("c_name")) )
			,"HIY") );
	
    if ( ! succeed ) {
	tell_object(me,set_color(
		sprintf("%s突然转过头狠狠地瞪了你一眼，忿忿的向你冲过来 ...\n",
			target->query("c_name")),"HIM") );
	tell_object(target,set_color(
		sprintf("你突然感到怪怪的，原来是%s的手正在你的背包中摸啊摸的 ..\n"
			,me->query("c_name")),"HIY") );
	if ( !userp(target) || 
		(userp(target) && ((int)target->query_level() > 5 || (int)me->query_level()< 5)) ) {
		target->kill_ob(me);
		me->kill_ob(target);
        	me->block_attack(4);
        	me->set_temp("block_command",1);
        	me->set_temp("msg_stop_attack",
       			"( 哎呀 ! 偷东西被发现了，你一阵手忙脚乱！ )\n" );
       		call_out("remove_block",3,me);
	} else
		tell_object(me,"然後用力的瞪了你几眼，走了。\n");
    } else {
		if ( item ) {
			if ( !item->move(me))
				tell_object(me,set_color("呵呵呵 ... 得手了 ...\n","HIY"));
			else
				tell_object(me,set_color("呃 .. 太重了，拿不动 ...\n","HIC"));
		} else {
		if ( !wealth = target->query("wealth") ) {
			tell_object(me,"你努力的在他的钱包摸啊摸 ... 可是连一毛钱都找不到 ...\n");
			return 1;
		}
		coins = keys(wealth);
		type = coins[random(sizeof(coins))];
		coin = ( wealth[type] > 500 ? 500 - random(100) : random(wealth[type]+1) );
		if ( coin ) {
			tell_object(me,set_color("咦 ! 捞到了 ... 嘻嘻嘻 ... 你狠狠地捞了一大把钱币 ...\n","HIY"));
			me->add("wealth/"+type,coin);
			target->add("wealth/"+type,-coin);
		} else
			tell_object(me,"喔 ~~ 他好像发现了，你赶快把手缩回来，没偷到半毛钱 ...\n");
		}
    }
	return 1;
}
int check_steal(object me,object target)
{
	int level,iq,dex,kar,rate1,rate2;

	if ( target->query("no_steal") ) return 0;
//	level = (int)this_player()->query_level()*2-(int)target->query_level();
	iq = (int)me->query_stat("int")-(int)target->query_stat("int");
	dex = (int)me->query_stat("dex")-(int)target->query_stat("dex");
	kar = (int)me->query_stat("kar")-(int)target->query_stat("kar");
/*
	rate1 = level*level/8+kar+kar+dex+dex+iq;
   	rate1 = rate1*(int)me->query_skill("steal")/100;
   	rate1 = ( rate1 > 93 ? 93 : rate1 ) ;
	rate2 = level*level/6+kar+dex+iq;
   	rate2 = (rate2 + (int)me->query_skill("peep"))/2;
   	rate2 = ( rate2 > 93 ? 93 : rate2 ) ;
*/
	level = (int)me->query_skill("peep")/5 - (int)target->query_level() +5;
	level = ( level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
	rate1 = RATE[level] + iq + iq + dex + kar ;
	if ( random(120) > rate1 ) return 0;
	level = (int)me->query_skill("steal")/5 - (int)target->query_level() +5;
	level = ( level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
	rate1 = RATE[level] + iq + dex + dex + kar ;
	if ( random(120) > rate1 ) return 0;
	return 1;
/*
   	if ( (random(100) < rate1) && (random(100) < rate2 ))
   		return 1;
   	else
   		return 0;
*/
}
int help();
int cmd_steal(string arg)
{
	string tmp1,tmp2;
	object target,item;

	if ( this_player()->query_temp("stealed") )
		return notify_fail("你只有三只手，而且第三只已经伸出去了 ...\n");
	if ( ! arg )
		return notify_fail("你要偷谁的东西？\n");

	if ( sscanf( arg,"%s from %s",tmp1,tmp2) != 2 ) return help();
		if ( ! target = present(tmp2,environment(this_player()) ) )
			return notify_fail("这里没有叫"+tmp2+"的生物。\n");
		if ( ! living(target) )
			return notify_fail("这里没有叫"+tmp2+"的生物。\n");
		if ( tmp1 != "money" && ! item = present(tmp1,target ) )
			return notify_fail(target->query("c_name")+"没有带著叫"+tmp1+"的东东。\n");

	if ( target == this_player() )
		return notify_fail("偷自己的东西做什麽啊?\n");
// 预防利用偷东西失败攻击 no_attack mob
	if ( target->query("no_attack") )
		return notify_fail("你不能偷他的东西。\n");
// 不能偷 invisible 的 player
	if ( !visible(target,this_player()) || target->query("invisible_player") ) 
		return notify_fail("三八 !! 你想偷谁啊 ？\n");

	if ( wizardp(target) ) {
		write("你怎麽能偷劳苦功\高的巫师呢？\n");
		return 1;
	}

        if ( userp(target) ) {
                if ( (int)target->query_level()< 5 ||
                         (int)this_player()->query_level()<5 )
                return notify_fail("你不能偷他 !!\n");
        }

	if ( item && (item->query("prevent_drop") || item->query("wielded") ||
			item->query("equipped")) ) 
	return notify_fail("别傻了 !! 这件东西你偷不走的 ...\n");
	write(set_color(sprintf("你开始用眼角的馀光偷偷留意%s的一举一动 ...\n",
			target->query("c_name") ),"HIY"));
	this_player()->set_temp("stealed",1);
	call_out("steal_idle",5+random(4),this_player(),
			check_steal(this_player(),target),target,item );
	return 1;
}

int help()
{
	write (@HELP
Usage: steal <object> from <target>
	   steal money from <target>

这个指令能使你在别人毫不知觉的情况下偷走他没有装备的物品、金钱甚至
他背包里的袋子。在下手"借"别人的东西之前，最好养成先观察观察的好习
惯，随手乱摸是很容易被发现的。

HELP
);
	return 1;
}
