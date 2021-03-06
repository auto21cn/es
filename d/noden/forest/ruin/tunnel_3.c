#include "ruin.h"
inherit ROOM;

void create()
{
	::create();
	set("light",0);
	set_short("通道");
	set_long(@CLong
这里是条南北方向的通道, 上下左右的墙壁均是由石块砌成的, 看来
相当地雄伟壮观。通道的两侧排列著精美的石雕像, 而且各个都有不同的
神情姿势, 令人为建造者的心思赞叹不已。
    由这里往南往北都是一片黑暗。
CLong
	);
	set("exits",([
		"south"	: RUIN"tunnel_2",
		"north"	: RUIN"tunnel_4",
		]));

        add( "item_desc", ([
                "statues"       : @C_ITEM_DESC_1
    这些石雕像都被安置於壁上一个个凹入的半圆形小洞中, 被维护得相
当好。他们的均是以小鬼族的造型来塑造的, 活泼的神情与栩栩如生的姿
态看来非常有趣。尤其当中有一只做伸手模样的小鬼真的是可爱极了。
C_ITEM_DESC_1
                ,"statue"       : @C_ITEM_DESC_2
    这个雕像刻著一只俏皮的小鬼, 伸著小手, 睁著大大的眼睛望著你,
让你忍不住想伸出手来碰碰它。
C_ITEM_DESC_2
                ]) );

	reset();
}

void init()
{
	add_action("do_touch_statue", "touch");
}

int is_a_user(object player)
{
	if( userp(player) ) return 1;
	return 0;
}

int do_touch_statue(string s)
{
	int i;
	object *players, me;
	
	if(!s) return notify_fail( "你要碰什麽?\n" );
	if( (s != "hand") && (s != "statue") )
		return notify_fail( "这里有这种东西吗?\n" );
	me = this_player();
	tell_room( environment(me),
		me->query("c_name") + 
		"摸了摸雕像的手, 突然地上出现一个大洞, 你掉了下去!!\n"
		,me
	);
	write(@ALONG
你摸了摸雕像的手, 正觉得很有趣时, 突然看见小鬼的嘴角竟露出奸笑! 
你感到: 不妙!!正想放手时....
突然脚底一空, 地上出现一个大洞, 你掉了下去!!
ALONG
	);
   me->set_explore("noden#17");
	players = filter_array(
		all_inventory(this_object()),"is_a_user", this_object());
	for( i=0; i<sizeof(players); i++ ) {
		players[i]->move_player(RUIN"mob_storage","SNEAK");
		tell_room(environment(players[i]),
			players[i]->query("c_name")+"掉了下来。\n", players[i]
		);
	}	
	return 1;
}
