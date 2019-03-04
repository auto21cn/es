// easta_army.c 
#include <mudlib.h>
#define HEADQUARTER "/d/eastland/easta/daemons/army_d"

inherit MONSTER;

void create()
{
	::create();
	HEADQUARTER->add_member();
}

void remove()
{
	HEADQUARTER->remove_member();
	return ::remove();
}

int stop_attack()
{
	HEADQUARTER->add_huntee(this_player());
	return 0;
}

void pseudo_hunt(object me, object player)
{
        if( this_object()->query_attacter() == player ) return ;
 	if( environment() && present(player, environment()) ) 
		if( this_object()==me )
			tell_room( environment(), 
				query("c_name") + "发现你的意图，大叫: 兄弟们！看清楚这家伙，别让他跑了！\n",
				this_object() );
		else {
			tell_room( environment(), 
				query("c_name") + "冲到你面前，大喝:「大胆刁民，竟敢到若岚城撒野！」\n",
				this_object() );
			if( !pointerp(attackers) || member_array(player, attackers)==-1 )
				kill_ob(player);
		}
	else if( !pointerp(will_attack) )
		will_attack = ({ player });
	else if( member_array(player, will_attack)==-1 )
		will_attack += ({ player });
}
