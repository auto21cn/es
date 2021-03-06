// This is a study object which provides a simple command to let player
// list and learn gonfus of scholars.
// Created by Layuter @Eastern.Stories (4-10-94)

#include <mudlib.h>

mapping gonfus;

// This function setups the gonfuss can be learned. The format is:
// ([ <gonfus-name> : ({ <required_level>,<required_skill>,<required_piety> }), 
//    <gonfus-name> : ({ <required_level>,<required_skill>,<required_piety> }), 
//                         :
//                         : ])
void set_gonfus(mapping s)
{
	gonfus = s;
}

mapping query_gonfus()
{
	return gonfus;
}

// This function checks if a player can learn a certain gonfus. If the third
// argument is given, spell level is also checked. Return 1 if the player
// can learn the gonfu ( at specified level, or 0 for default )
varargs int can_train_gonfu(object player, string gonfu)
{
	if( !gonfus || !mapp(gonfus) || !gonfu || undefinedp(gonfus[gonfu]) )
		return 0;
	if( (int)player->query_level() >= gonfus[gonfu][0] )
		return 1;
	else return 0;
}

// This function returns experience required to raise this gonfu. If
// something goes wrong, -1 is returned.
int raise_cost1(object player, string gonfu)
{
    int skill;	

	if( !gonfus || !mapp(gonfus) || !gonfu || undefinedp(gonfus[gonfu]) )
		return -1;
	else 	
	    skill = gonfus[gonfu][1]; 
	return (skill-(int)player->query_skill("palaeography"));
}

int raise_cost2(object player, string gonfu)
{
    int piety;

        if( !gonfus || !mapp(gonfus) || !gonfu || undefinedp(gonfus[gonfu]) )
                return -1;
        else
            piety = gonfus[gonfu][2];
        return (piety-(int)player->query_perm_stat("piety"));
}

// *************************************************************************
// The following are default commands for gonfu rooms. You can alter it in
// your code if you think it is needed.
// *************************************************************************

void init()
{
	add_action( "do_train", "train" );
}

int do_train(string arg)
{
	int skill;
	string s;

	if( !arg || arg=="" )
		return notify_fail( 
			"指令格式: train <剑法名称>\n" );
	if( !undefinedp(this_player()->query("scholar_gonfu/"+arg)) )
		return notify_fail( 
			"这个剑法你已经学会了，你不须要再学一次。\n");
	if( !can_train_gonfu( this_player(), arg ) )
		return notify_fail( 
			"对不起，你现在的等级无法学此剑法....。\n");
	
	if( (raise_cost1(this_player(), arg, )) > 0 ) {
	  write("对不起，你现在的古文学技能还不够，还没有办法学此剑法。\n");
  	  return 1;
	}

        if( (raise_cost2(this_player(), arg, )) > 0 ) {
          write("对不起，你现在的虔诚度还不够，还没有办法学此剑法。\n");
          return 1;
        }

	write( 
		"经过一番苦练，你终於学会"+ to_chinese(arg) + "剑法\n");
	this_player()->set("scholar_gonfu/"+arg, 0);
	return 1;
}
