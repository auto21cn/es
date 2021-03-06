#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "快意堂" );
        set_long(
@LONG
这里是本镇最大的赌坊，只听到一阵阵呼芦喝雉之声，鳖十板凳喊的
通天价响，穿插著几声「洗拔辣」，真是乱的一榻糊涂。快意堂名义上是
暴发户钱不多的产业，事实上却是由某帮会托管，所以这里除了偶而争钱
斗殴的小事外，一向没有大案发生，不过捕快们还是很乐意常常来走走，
补贴补贴微薄的薪水。
LONG
        );
        
        set( "exits", ([
                "north" : Goomay"kwi_yi2",
		"south" : Goomay"row15",
        ]) );
        
        set( "objects", ([
                "gambler1" : Mob"gambler",
                "gambler2" : Mob"gambler",
                "gambler3" : Mob"gambler",
                "gambler4" : Mob"gambler",
                "guard1"   : Mob"body_guard",
                "guard2"   : Mob"body_guard",
        ]) );
        set( "pre_exit_func", ([
                "north" : "can_pass" ]) );
        reset();
}

int can_pass()
{
	if (present("bodyguard",this_object()) && !wizardp(this_player()))
	{
		tell_object(this_player(),
		"保镖挡在你面前说道：「堂主正在喝酒 !! 不喜欢有人打扰 !!」\n");
	return 1;
	}
	else
        return 0;
}
