// this file will included by some monk in saulin. added by Kyoko.
#include "../saulin_temple.h"
#include <mudlib.h>
inherit MONSTER;

void relay_message(string class1, string msg)
{
	string name,str;
	object who;
	if (!msg || sscanf( msg, "%s(%s)走了过来。", str,name )!=2 ) return;
                if( !who = find_player(lower_case(name)) ) return;
	if(!who->query_temp("saulin_killer") ) return;
	tell_room( environment(who), 
		sprintf("%s对著%s大叫: 你竟敢在寺内杀人!!\n" ,this_object()->query("c_name"),who->query("c_name")), ({ this_object(), who })
	);
	tell_object( who, 
		sprintf("%s对著你大叫: 你竟敢在寺内杀人!!\n",this_object()->query("c_name"))
	);
	this_object()->kill_ob(who);
}

void die()
{
	object killer;
	killer = this_object()->query("last_attacker");
	killer->set_temp("saulin_killer", 1);
	::die();
}
