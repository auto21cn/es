// this file is called by every guard files
#include <mudlib.h>
#include <move.h>
#include <daemons.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set("forgetful",1);
	set("critical_med_res",500);
	HEAL_BODY->apply_effect(this_object(),30,7);
	set("npc",0);
}

int filter_invis(object ob, object carrier)
{
	return visible(ob,carrier);
}

int check_item()
{
	object *items, me, ob;
	int coin, i, x, count;
	string result, tmp, *names, unit;
	mapping inv;

	count = 0;

	me = this_object();
	
	items = filter_array(all_inventory(me), "filter_invis", this_object(), me);
	for (i = 0; i < sizeof(items); i++)
		if(items[i]->query("short"))
			count++;
	result = "你的贴身侍卫说道:启禀大人,";		
	result += count? ("我现在总共带著 "+count+" 样物品")
			 : ("我现在身上没有任何东西");

	result += sprintf("\n(总重量 %d.%d 公斤, 上限 %d.%d 公斤)\n",
		(int)me->query("load")/10,
		(int)me->query("load")%10,
		(int)me->query("max_load")/10,
		(int)me->query("max_load")%10);

	ob = me->query_temp("mounting");
	if( ob ) result += 
		"我现在正骑在一" + ob->query("unit") + ob->query("c_name") + "上，有 * 记号的物品\n"
		"表示正驮在它身上。\n";

	for (x=0; x < sizeof(items); x++) {
		if(tmp=(string)items[x]->query("short")) {
		tmp += " ("+items[x]->query("name")+")";
		if(items[x]->query("wielded")) tmp += " (武器)";
		if(items[x]->query("equipped")) tmp += " (护甲)";
		if(items[x]->query("invisible")) tmp += " (隐形)";
		if(items[x]->query("mounted")) tmp += " (座骑)";
		if(items[x]->query("secure")) tmp += " [标记设定]";
		if(items[x]->query("on_mounted")) result += "* " + tmp + ".\n";
			else result += "  " + tmp + ".\n" ;
		}
	}

	write(result);
	return 1;
}



int report_stat()
{
	string *coins, *list, *statnames, *skillnames;
	object ob;
	mapping skills, stats, wealth, conds;
	mixed cond_name;
	int i, limit, flag, exp_reward;
	string cond_str;

	ob = this_object();

	printf(inverse("[ %2d ]")+bold(" %s\n\n"), ob->query_level(),
		ob->query("short"));

	conds = (mapping)ob->query("conditions");

	cond_str = "";
	if( sizeof(conds) ) {
		cond_name = keys(conds);
		for( i=0, limit=sizeof(cond_name); i<limit; i++ ) {
			if( cond_name[i][0] == '_' ) continue;
			cond_str += to_chinese(cond_name[i]);
		}
	}
	if( cond_str == "" ) cond_str = "正常";
	
	write("状  态: "+ cond_str + "\n" );

	write("经  验: "+ob->query_experience() );
        write("\n状  况: "+STATS_D->body_status_string(ob));
        


	if( ob->query("max_hp") ) write( 
		"\n体  力: "+ob->query("hit_points")+"/"+ ob->query("max_hp")+"\n");

	write( "\n" );
	statnames = STATS_D->query_stat_names();
	for (i=0;i<sizeof(statnames);i++)
		printf("%12-s : %d (%d)\t\t%s",
			to_chinese(statnames[i]), 
			ob->query_stat(statnames[i]),
			ob->query_perm_stat(statnames[i]),
			(i%2)?"\n":"" );
	write ("\n");

	wealth = ob->query("wealth") ;
	if (!wealth) {
		write ("身无分文。\n");
	} else {
		coins = keys(wealth) ;
		list = sort_array(coins,"sort_coins",this_object()) ;
		flag=0 ;
		for (i=0;i<sizeof(coins);i++) {
			if (wealth[list[i]]>0) {
				printf( "   %15-s %d\n", 
					to_chinese(list[i] + " coin"),
					wealth[list[i]]);
				flag=1 ;
			}
		}
		if (flag==0) write( "身无分文。\n");
	}

	skills = ob->query_skills() ;
	if (skills && sizeof(skills)) {
		skillnames = keys(skills) ;
		write ("\n") ;

		list = sort_array(skillnames, "sort_skills", this_object()) ;
		for (i=0;i<sizeof(skills);i++)
			printf("%12-s(%12-s) : %3-d\t%s",
				to_chinese(list[i]), capitalize(list[i]),
				skills[list[i]], i%2?"\n":"");
		write( "\n" );
	}
	return 1 ;
}

int sort_skills (string s1, string s2) {
	return strcmp( s1, s2 );
}


int sort_coins(string s1, string s2) {
	return (coinvalue(s1)<coinvalue(s2)) ;
}

void distruct(object guard)
{
	int i;
	object* all_eq;
	
        guard->delete("weapon1");
	guard->delete("weapon2");
	all_eq=all_inventory(guard);
        for ( i=sizeof(all_eq)-1 ; i >-1 ; i--) {
        	if (all_eq[i]->query("equipped")) all_eq[i]->delete("equipped");
                all_eq[i]->remove();
        }
	guard->remove();
}


void disappear(object guard)
{
	
	string guard_name;
        
        if( !guard ) return;
        guard_name=guard->query("c_name");
        tell_room( environment(guard),
        	sprintf("%s的长官失踪了,%s决定尽快赶回诺达尼亚向国王报告。\n",
        		guard_name,guard_name)
        );
	distruct(guard);
}

void receive_message(string class1, string msg)
{
	string who, dir, master, item;
	object master_player;
        
        master_player = (object)this_object()->query("guard_master");
        
// if no master or master dead, then destruct me, wuwu.....
	if( !master_player ) {
        call_out("disappear",2,this_object());
		return;
	}
        if ( present(master_player,environment(this_object())) )
	    return;
	if ( !query("stop") )
		this_object()->move_player( environment(master_player), "" );
	    return ;
}

int order_me(string arg)
{
	object master_player;
	string dir;
	
	master_player = (object)this_object()->query("guard_master");
	if( !master_player ) {
        	call_out("disappear",2,this_object());
		return 0;
	}
	if( this_player() != master_player ) return 0;
// make the order cmd work.
	if( !arg || arg =="suicide" || arg == "quit" || 
	    sscanf(arg,"drop %s",dir) || sscanf(arg,"give %s",dir) ||
	    sscanf(arg,"party %s",dir) )
		return notify_fail("你的贴身侍卫露出迷惑的眼神, 似乎不明白你的意思!\n");
	if( arg == "stay" ) {
		tell_object( master_player, 
			"你的贴身侍卫立正站好, 一动也不动。\n" 
		);
		this_object()->set("stop", 1);
	} else if( arg == "follow" ) {
		tell_object( master_player, 
			"你的贴身侍卫站到你的左後方, 跟著你行动。\n" 
		);
		this_object()->set("stop", 0);
	} else if ( arg == "dismiss" ) {
		tell_room(environment(this_object()),sprintf(
			"%s说道:遵命, 在下立刻回诺达尼亚向雷思团长覆命。\n%s转身离开了。\n",
			this_object()->query("c_name"),this_object()->query("c_name"))
		);
		master_player->delete_temp("now_guard");
		call_out("distruct",1,this_object());
	} else if ( arg == "report" ) {
		report_stat();
	} else if ( arg == "check_item" ) {
		check_item();
	} else command(arg);
/*	if (!command(arg)) {
		return notify_fail("你的贴身侍卫露出迷惑的眼神, 似乎不明白你的意思!\n");
	}
*/	;
    return 1;
}

void set_master(object master,object guard)
{
	object ob;
	string c_name, name;
	
	if( !master ) return;
	ob = this_object();
	name = (string)ob->query("post_name");
	c_name = (string)ob->query("c_post_name");

	ob->set("mountable",0);
	ob->set("guard_master", master);
	ob->set("name", master->query("name")+name);
	ob->add("id",({ (string)ob->query("name") }) );
	ob->set("c_name", master->query("c_name")+c_name);
	ob->set("long" , sprintf("%s不过他现在正担任%s的贴身侍卫\n%s%s",
			guard->query("long"),
			master->query("c_name"),
			"如果你是他的主人, 可以用order_guard <command> 命令他\n",
			"你也可以用help_guard来了解更多他能做的事。\n")
	);
	ob->set("short", sprintf("%s%s[由%s转职]",
		master->query("c_name"),c_name,guard->query("short") )
	);
	ob->set("wimpy", 90);
	ob->set("stop", 0);
	ob->set("brief",1);
}

void die()
{
	object killer, master;
	int score,lost_score;
	killer = (object)this_object()->query("last_attacker");
	master = (object)this_object()->query("guard_master");
	if( killer && master ) {
	  tell_object( master, 
		sprintf("\n%s说: 对不起, 属下无能保卫诺达尼亚....然後就挂了:(\n",
			this_object()->query("c_name"))
	  );
	}
	master->set_temp("now_guard", 0);
	score = master->query("war_score");
	lost_score = query("war_score");
	if ( (score = score - lost_score) > 0 ) master->set("war_score",score);
	else master->set("war_score",0);
	tell_object(master,sprintf("%s%s%d%s",
		"由於你的领导无方, 使诺达尼亚损失一名精锐的士兵, \n",
		"耶拉曼决定扣你",lost_score,"点战功以示惩戒。\n")
	);	
	::die();
}

int help_order(string arg)
{
	write( @HELP
要叫侍卫做事, 可用
order_guard <command>
command 可为一般 user 使用的指令, 但侍卫不能丢弃任何东西,
也不能把东西给别人。
另外侍卫还有几项专用指令:
1. stay   :命令侍卫留在原地。
2. follow :命令侍卫跟著你行动。
3. dismiss:任务结束, 让侍卫返回诺达尼亚报告, 听候雷思团长指示。
4. report :让侍卫向你报告他的状态。
5. check_item: 让侍卫报告身上有哪些物品。
HELP
	);
	return 1;
}

int block_wear(object obj)
{
	string *allow_types = ({ "body", "head", "arms", "hands", "legs",
			"feet", "shield", "cloak", "misc","finger" });
                     
	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}
