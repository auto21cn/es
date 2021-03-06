////#pragma save_binary

// This is a study object which provides a simple command to let player
// list and learn spells.
// Created by Annihilator@Eastern.Stories (12-17-93)
// Updated by Kyoko@Eastern.Stories (3-10-94)

#include <mudlib.h>

mapping spells;

// This function setups the spells can be learned. The format is:
// ([ <spell-name> : ({ <spell_system>, <skill_required>, <max_level>, 
//                      <skill_per_level>, <exp_proportion(%)>  }), 
//    <spell-name> : ({ <spell_system>, <skill_required>, <max_level>, 
//                      <skill_per-_evel>, <exp_proportion(%)>  }), 
//                         :
//                         :
void set_spells(mapping s)
{
	spells = s;
}

mapping query_spells()
{
	return spells;
}

// This function checks if a player can learn a certain spell. If the third
// argument is given, spell level is also checked. Return 1 if the player
// can learn the spell ( at specified level, or 0 for default )
varargs int can_learn_spell(object player, string spell, int level)
{
	int extra;

	if( !spells || !mapp(spells) || !spell || undefinedp(spells[spell]) )
		return 0;
	if( !level ) {
		if( (int)player->query_skill( spells[spell][0] ) >= spells[spell][1] )
			return 1;
		else return 0;
	} else {
		if( level > spells[spell][2] ) return 0;
		if( (int)player->query_skill( spells[spell][0] ) >=
		       spells[spell][1] + spells[spell][3] )
			return 1;
		else return 0;
	}
}

// This function returns experience required to raise a spell level. If
// something goes wrong, -1 is returned.
int raise_cost(object player, string spell)
{
	int skill, level, exp;

	if( !spells || !mapp(spells) || !spell || undefinedp(spells[spell]) )
		return -1;
	if( undefinedp(level= (int)player->query("spells/"+spell)) )
		return 0;
	if( level >= spells[spell][2] ) return -2;
	skill = spells[spell][1] + spells[spell][3] * (level+1);
	if( skill > 100 ) skill = 100;
	if( (int)player->query_skill( spells[spell][0] ) < skill )
		return 0;
	exp = spells[spell][4] * spells[spell][1] * spells[spell][1] 
	      * (level+1) * (level+1) / 100 ;
	exp -= ((int)player->query_perm_stat("pie")-15) * exp / 30;
	return exp;
}

// *************************************************************************
// The following are default commands for study rooms. You can alter it in
// your code if you think it is needed.
// *************************************************************************

void init()
{
	add_action( "do_study", "study" );
	add_action( "do_raise", "raise" );
}

void view_catalog()
{
	mapping spells;
	string *s;
	int i, chinese_mode;

	chinese_mode = can_read_chinese();
	printf( "%-30s  %-15s  %-8s  %-8s\n",
		chinese_mode? "法术名称": "Spell", chinese_mode? "法术种类": "Type",
		chinese_mode? "所需技能": "Skill", chinese_mode? "最大级数": "Max Lvl" );
	write( "=====================================================================\n");
	spells = query_spells();
	s = keys(spells);
	for( i=0; i<sizeof(s); i++ ) {
		printf( "%-30s  %-15s  %5d     %6d\n",
			chinese_mode? to_chinese(s[i]) + " (" + s[i] + ")": capitalize(s[i]),
			chinese_mode? to_chinese(spells[s[i]][0]): spells[s[i]][0],
			spells[s[i]][1], spells[s[i]][2] );
	}
	write( "=====================================================================\n");
}

int do_study(string arg)
{
	int chinese_mode;

	chinese_mode = can_read_chinese();
	if( !arg || arg=="" )
		return notify_fail( chinese_mode?
			"指令格式: study <法术名称>\n": "Syntax: study <spell>\n" );
	if( !undefinedp( this_player()->query("spells/"+arg) ) )
		return notify_fail( chinese_mode?
			"这个法术你已经学会了，你可以试用(raise)提升法术等级。\n":
			"You already learned this spell, you can try \"raise\" the spell level.\n" );
	if( !can_learn_spell( this_player(), arg ) )
		return notify_fail( chinese_mode?
			"对不起，你现在的魔法技能还没有办法学习这种法术....。\n":
			"Sorry, you cannot learn such spell by now.\n" );
	write( chinese_mode?
		"经过一番耐心的研读，你学会了初级的" + to_chinese(arg) + "法术！\n":
		"After studying hard with the books, you learned the basic of "+arg+" spell!\n");
	this_player()->set("spells/"+arg, 0);
	return 1;
}

int do_raise(string arg)
{
	mapping my_spells;
	string *s;
	int i, exp, chinese_mode;

	chinese_mode = can_read_chinese();
	if( !arg || arg=="" ) {
		my_spells = this_player()->query("spells");
		if( !my_spells || !mapp(my_spells) || sizeof(my_spells) < 1 ) {
			write( chinese_mode?
				"你目前并没有学过任何法术。\n": "You don't know any spell by now.\n" );
			return 1;
		}
		s = keys(my_spells);
		printf( "%-30s  %-8s  %s\n", chinese_mode? "法术名称": "Spell",
			chinese_mode? "目前等级": "Level", chinese_mode? "提升等级所需经验": "Exp. Required" );
		write( "============================================================\n");
		for( i=0; i<sizeof(s); i++ ) {
			if( undefinedp( spells[s[i]] ) ) continue;
			exp = raise_cost( this_player(), s[i] );
			if( exp < 1 )
				printf( "%-30s  %6d    目前已达最大等级\n",
					chinese_mode? to_chinese(s[i]) + " (" + s[i] + ")": capitalize(s[i]),
					my_spells[s[i]] );
			else
				printf( "%-30s  %6d    %10d\n",
					chinese_mode? to_chinese(s[i]) + " (" + s[i] + ")": capitalize(s[i]),
					my_spells[s[i]], raise_cost( this_player(), s[i] ) );
		}
		write( "============================================================\n");
		return 1;
	}
	
	if( undefinedp( this_player()->query("spells/"+arg) ) ) {
		write( chinese_mode?
			"这种法术你没有学过，请用(study)研读过再来。\n":
			"You havn't learned such spell yet. Please study it first.\n" );
		return 1;
	}
	if( raise_cost(this_player(), arg) == -2 ) {
	    write( chinese_mode?
			"对不起，这法术在这里你只能学到这个级数。\n":
			"Sorry, you have learned this spell as maximum level here.\n" );
		return 1;
	}
	if( (exp = raise_cost(this_player(), arg)) < 1 ) {
		write( chinese_mode?
			"对不起，你现在的法术知识还没有办法提升这个法术的威力。\n":
			"Sorry, but your skill is not high enough to riase the spell level.\n" );
		return 1;
	}
	if( (int)this_player()->query_exp_stock() < exp ) {
		write( chinese_mode?
			"你现在要提高这个法术的等级，需要 "+exp+" 点经验。\n":
			"You need "+exp+" experience to raise the spell level.\n" );
		return 1;
	}
	write( chinese_mode?
		"经过一番耐心的研读之後，你对"+to_chinese(arg)+"法术的领悟又更进一层了！\n":
		"After studying hard with the books, you feel more advanced with the spell!\n" );
	this_player()->gain_experience( -exp );
	this_player()->add("spells/"+arg, 1 );
	return 1;
}
