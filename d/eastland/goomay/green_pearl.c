#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short("绿珠楼" );
        set_long(
@LONG
这里是大财主钱不多特地为他的宠妾－绿珠所建造的一座小楼，
装饰却一点都不豪华，净素的墙面上挂著几幅水墨山水，两扇琉璃
窗使得整个前厅显得十分洁净优雅。你可以想见这里的主人一定是
个很懂得生活的人。
LONG
        );
        
        set( "exits", ([ 
		"east" : Goomay"rich_house",
		"up"   : Goomay"green_pearl2",
        ]) );
        set( "objects", ([
                "maid1" : Mob"maid",
		]));
        set( "pre_exit_func", ([
                "up" : "can_pass" ]) );
        reset();
}

int can_pass()
{
	if(!this_player()->query_temp("give_pearl") && !wizardp(this_player()))
        {
                tell_object(this_player(),
                "婢女叉著腰挡在你面前说道：「你这个人怎麽一点礼貌都不懂吗？乱闯人家家里 !!」\n");
		return 1;
	}
	else
	return 0;
}
