// This is a study object which provides a simple command to let player
// list and train gonfus.
// Created by Layuter @Eastern.Stories (4-10-94)
// Modify by angel for Monk... :) (5-8-94)
// Modify by Kyoko. for 2 types of gonfus. (10-18-94)
#include <mudlib.h>

mapping gonfus;
string type;

// This function setups the type of gonfus that he learn now.
// Now has: fist, heal, general.
void set_gonfu_type(string s)
{
	type = s;
}

// This function setups the gonfus can be learned. The format is:
// ([ <gonfus name> : ({ <skill type>, <skill need>, <exp> }), 
void set_gonfus(mapping s)
{
	gonfus = s;
}

mapping query_gonfus()
{
	return gonfus;
}

// This function checks if a player can learn a certain gonfus. 
int gonfu_exist(string gonfu)
{
	if( !gonfus || !mapp(gonfus) || !gonfu || undefinedp(gonfus[gonfu]) )
		return 0;

	return 1;
}

int check_skill(object player, string gonfu)
{
	if( (int)player->query_perm_skill(gonfus[gonfu][0]) < gonfus[gonfu][1] )
		return 0;
	return 1;
}

// This function returns experience required to raise this gonfu. 
int raise_cost(object player, string gonfu)
{
    int exp;	

	exp = gonfus[gonfu][2]; 
	exp -= exp * ((int)player->query_perm_stat("pie")-15) / 30;
	if( exp < 0 ) exp = 0;
	return exp;
}

// *************************************************************************
// The following are default commands for gonfu rooms. You can alter it in
// your code if you think it is needed.
// *************************************************************************
void init()
{
	add_action( "do_train", "train" );
}

void view_catalog()
{
	mapping gonfus;
	string *s;
	int i, exp,chinese_mode;

	chinese_mode = can_read_chinese();
	printf( "%-31s  %-12s %-7s\n",
		chinese_mode? "武学名称": "Gonfu", chinese_mode? "武术分类": "level",
		chinese_mode? "所需技能值":"skill levels" );
	write( "=====================================================================\n");
	gonfus = query_gonfus();
	s = keys(gonfus);
	for( i=0; i<sizeof(s); i++ ) {
		printf( "%-30s   %5s     %6d\n",
			chinese_mode? to_chinese(s[i]) + " (" + s[i] + ")": capitalize(s[i]),
			chinese_mode? to_chinese(gonfus[s[i]][0]): gonfus[s[i]][0],
			gonfus[s[i]][1]);
	}
	write( "=====================================================================\n");
}


int do_train(string arg)
{
	int chinese_mode, exp, tmp;
	string *tmp2;
	object me;

	if( type != "general" && type != "heal" && type != "fist" ) return 0;

	me = this_player();
	chinese_mode = can_read_chinese();
	if( !arg || arg=="" )
		return notify_fail( chinese_mode?
			"指令格式: train <功\夫名称>\n": "Syntax: train <gonfu>\n" ); 

	if( type != "general" )
		tmp2 = (string *)me->query("monk_gonfu/"+type);
	if( (type == "general" && !undefinedp(me->query("monk_gonfu/"+arg))) ||
		(tmp2 && member_array(arg, tmp2) != -1) ) {
		write( chinese_mode?
			"这个功\夫你已经学会了，不需要再学一次!\n":
			"You have already learned this gonfu, you dont need train again.\n" );
		return 1;
	}

	if( !gonfu_exist(arg) ) {
		write ( chinese_mode?
			"本室并不传授你所要学的那套功\夫! (打错字了吧) \n":
			"Sorry, you cannot learn such gonfu here.\n" );
		return 1;
	}
	
	if( !check_skill(me, arg) ) {
		write( chinese_mode?
			"你的技能造诣不足，再练几年再来吧! \n":
			"Sorry, you cannot learn such gonfu because your skill is lower.\n" );
		return 1;
	}	

	exp = raise_cost(me, arg);
	tmp = exp - (int)me->query_exp_stock();
	if( tmp > 0 ) {
		write( chinese_mode?
			"你现在要学此武术，还需要 "+tmp+" 点经验。\n":
			"You need "+tmp+" experience to train the gonfus.\n" );
		return 1;
	}

	write( chinese_mode?
		" *** 经过一番苦练，你终於学到了 "+ to_chinese(arg) + " *** \n":
		"After training hard with the books, you finally learn "+arg+" !\n");

	if( type == "general" )
		me->set("monk_gonfu/"+arg, 0);
	else {
		if( tmp2 ) tmp2 += ({ arg });
		else tmp2 = ({ arg });
		me->set("monk_gonfu/"+type, tmp2);
	}
	me->gain_experience( -exp );	
	return 1;
}
