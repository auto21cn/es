// Created by Aquarius@EasternStory
#include <mudlib.h>
inherit OBJECT;
int be_stick ;

void create()
{
     be_stick = 0;
     seteuid(getuid());
     set_name("scotch tape","特制胶带");
     add("id",({"tape"}));
     set("short","@@query_short");
     set_long(@LONG
一卷特制胶带, 黏性超强, 遇水不脱落, 贴不紧退钱。 
使用方法 : stick tape on <something>." 
LONG );
     set( "unit", "卷");
     set("weight",1);
     set("value", ({ 40, "silver" }));
//     set("amount",1);
}

string query_short()
{
    if ( be_stick == 0 ) {
    	return "特制胶带";
    } else {
	if ( this_player() == environment(this_object()) ) 
		return "一卷贴在你嘴上的特制胶带";
	else
		return sprintf("一卷贴在%s嘴上的特制胶带",environment(this_object())->query("c_name")) ;
    }	
}

void init()
{
	if ( be_stick ) {
		add_action("do_tear","tear");
		add_action("do_say","say");
		add_action("do_say","shout");
		add_action("do_say","cast");
		add_action("do_say","whisper");
		add_action("do_say","knight");
		add_action("do_say","monk");
		add_action("do_say","scholar");
		add_action("do_say","adv");
		add_action("do_say","mage");
		add_action("do_say","healer");
		add_action("do_say","tell");
		add_action("do_say","es");
		add_action("do_say","chat");
		add_action("do_say","songin");
	} else if ( userp(this_player()) ){
		add_action("do_put","stick");
	}
}

int do_say(string arg)
{
	if ( ! be_stick ) return 0;
	write("你的大嘴巴被胶带(tape)贴住了, 先把胶带撕(tear)下来吧。\n");
	tell_room(environment(previous_object()),sprintf("%s支支吾吾的不知道在说什麽。\n",previous_object()->query("c_name")),previous_object());
	return 1;
}

int do_tear(string arg)
{
	if ( ! id(arg) ) return 0;
	write("你撕下胶带。\n");
	tell_room(environment(this_player()),this_player()->query("c_name")+"撕下胶带。\n",this_player());
	this_player()->delete_temp("silence");
	return this_object()->remove();
}

int npc_do_tear(object me)
{	
	if (me) {
	tell_room(environment(me),me->query("c_name")+"撕下胶带。\n");
	me->delete_temp("silence");
	}
	return this_object()->remove();
}

int do_put(string arg)
{
	object env,dest,me;
	int skill,succeed;
	string name,ob_name;
	if( be_stick==1 ) return notify_fail("这胶带已经在使用中了。\n");
	if ( sscanf(arg,"%s on %s",ob_name,name) != 2 ) return 0;
	if ( ! id( ob_name ) ) return notify_fail("贴什麽 ?\n");
	me = this_player();
	env = environment(me);
	dest = present(name,env);
	if ( me->query_temp("doing_backstab") )
		return notify_fail("你正想要暗算别人，没空分心去贴胶带。\n");
	if ( me->query_current_attacker() ) {
		return notify_fail("你正忙著战斗, 哪有空贴胶带呢?\n");
	}
	if ( ! dest ) return notify_fail(name+"不在这边。\n");
	if ( ! living(dest) ) {
		write("你用胶带把"+dest->query("c_name")+"贴的密不通风。\n");
		tell_room(env,sprintf("%s拿著胶布, 将%s胡乱贴一通。\n",me->query("c_name"),dest->query("c_name") ),({me}));
		this_object()->remove();
		return 1;
	}
/* 	since player 被贴不会互 k, we don't have to check that ..
	if ( (int) me->query_level() < 5 ) {
		return notify_fail("你的等级太低了, 最好不要乱贴...\n");
	}
*/
	if ( userp(dest) && (int)dest->query_level() < 5 ) {
		return notify_fail("请不要欺负弱小..\n");
	}

	if ( dest == me ) {
		tell_room(env,sprintf("%s用胶带把自己的嘴巴贴起来。\n",me->query("c_name")),me);
		write("你用胶带贴住自己的嘴巴。\n");
		be_stick = 1;
		this_object()->move(dest);
		this_object()->set("extra_look", "$N的大嘴巴上不知道被谁贴了胶带。\n");
		this_object()->set("prevent_drop",1);
		this_object()->set("prevent_insert",1);
		this_object()->set("long","这条胶带贴住你的嘴巴, 快把它撕掉吧!(tear tape)\n");
		return 1;
	}

	// max value of skill : lv 19 vs. lv 1 => 160 ( 19+24+18+100)
	skill = (int) me->query_stat("int")-(int) dest->query_stat("int");
	skill += (int) me->query_stat("kar")-(int) dest->query_stat("kar");
	skill -= (int) dest->query_level();
	skill += (int)me->query_skill("trick");
	succeed = ( skill > random(110) );

	write("你带著纯真无邪的笑容, 对著"+dest->query("c_name")+"笑一笑..\n");
	tell_room(env,me->query("c_name")+"带著纯真无邪的笑容, 对著"+
		dest->query("c_name")+"笑一笑...\n",({me,dest}));
	tell_object(dest,me->query("c_name")+"带著纯真无邪的笑容, 对你笑一笑..\n");

	if ( dest->query("no_attack") ) 
		return notify_fail( dest->query("c_name")+"对你笑一笑说道 : 小朋友, 这样不可以喔!\n");

	
	if ( succeed ) {
		write(sprintf("%s对著你愉快地笑著。\n",dest->query("c_name")));
		tell_room(env,sprintf("%s对著%s愉快的地微笑著。\n",dest->query("c_name"),me->query("c_name")),({dest,me}));
		tell_object(dest,sprintf("你对著%s愉快地笑著。\n",me->query("c_name")));
		be_stick = 1;
		tell_room(env, set_color(sprintf("\n突然%s以迅雷不急掩耳的速度掏出一卷胶带,二话不说贴向%s!!\n",me->query("c_name"),dest->query("c_name")),"HIY"),({me,dest}));
		write(set_color("\n你以迅雷不急掩耳的速度掏出一卷胶带,二话不说贴向"+dest->query("c_name")+"\n","HIY"),me);
		tell_object(dest,set_color("\n"+me->query("c_name")+"以迅雷不急掩耳的速度掏出一卷胶带,二话不说贴在你嘴上!!\n","HIY"));

		this_object()->move(dest);
		this_object()->set("extra_look", "$N的大嘴巴上不知道被谁贴了胶带。\n");
		this_object()->set("prevent_drop",1);
		this_object()->set("prevent_insert",1);
//		this_object()->set("short","一条正贴在某人嘴巴上的胶带");
		this_object()->set("long","这条胶带贴住你的嘴巴, 快把它撕掉吧!(tear tape)\n");
		if ( ! userp(dest) ) {
			me->kill_ob(dest);
			dest->kill_ob(me);
		}
		dest->block_attack( (skill > 60 ? 4 : 2) );
		dest->set_temp("msg_stop_attack",
			"( 你急著撕掉胶带, 没办法出手 ! )\n");
		dest->set_temp("silence");
		if ( ! userp(dest) )  // npc 自动撕掉, player 自己手动撕吧 !
//			call_out("npc_do_tear",6,dest );
			call_out("npc_do_tear",4 + skill/20 ,dest );
	} else {
	    if ( ! userp(dest) ) {
		tell_room(env,sprintf("%s突然大喝一声: 搞这种雕虫小技, 去死吧 !!\n",dest->query("c_name"),me->query("c_name")),({me,dest}));
		write(sprintf("%s突然大喝一声: 搞这种雕虫小技, 去死吧 !!\n",dest->query("c_name")));
		tell_object(dest,sprintf("你发现%s对你不怀好意, 於是发动攻击。\n",me->query("c_name")));
		me->kill_ob(dest);
		dest->kill_ob(me);
		me->set_temp("msg_stop_attack","( 你一阵手忙脚乱, 没办法出手! )\n");
		me->block_attack( 2 );
	   } else {
		write( sprintf("你的企图被识破了,%s对你笑一笑说道 : 小朋友, 这样不可以喔!\n",dest->query("c_name")) );
		tell_object(dest, sprintf("%s似乎有什麽企图。\n",me->query("c_name")) );
	   }
	}
	return 1;
}

