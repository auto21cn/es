//#pragma save_binary

#include "farwind.h"
#include <daemons.h>
#define BOARD FARWIND"bugsboard"

inherit ROOM ;

void create ()
{
        ::create();
        set_outside("farwind") ;
        set_short("远风镇广场");
        set_long(@C_LONG
你现在来到了远风镇的广场。广场中央有一座大理石喷泉，喷泉
(fountain)旁边立著一座钟楼(clock) ，上面标示著时间和日期。远
风镇的大街穿过广场向南北延伸，向西则是远风镇最繁华的微风路。
一座雄伟的英雄纪念馆位於广场的东边。
C_LONG
        );
        set( "light", 1 );
        
        BOARD->frog();
        
        set ("exits", ([
                "north" : FARWIND"nmain",
                "south" : FARWIND"smain",
                "east" : FARWIND"bazz1",
                "west" : FARWIND"ebazz",
        ]) );
        set("water_source", 1);
        set("item_desc", ([
                "fountain" : "这座大理石喷泉正源源不绝地涌出清冽的泉水。\n"
        ]) );
        set("item_func/clock","look_at_clock");
        set("objects", (["torch"    :FARWIND"monster/dance_torch",
                         "beggar"   :FARWIND"monster/beggar",
                         "sheriff"  :FARWIND"monster/sheriff",]) );

        reset();
}
void init()
{
	add_action("do_drink","drink");
}
int do_drink(string arg)
{
	object me;

	if(!arg || (arg!="water" && arg!="泉水")) 
            return notify_fail("你要喝什么? \n");
        me=this_player();
	if(me->query_level()<5 || wizardp(me) )
	{
		tell_object(me,"你把嘴凑向喷泉, 咕咚咕咚喝了几口泉水.... \n"
                               "你感到浑身舒畅, 似乎体力恢复了!\n");
		tell_room(this_object(), me->query("c_name") +
                 	  "把嘴凑向喷泉, 咕咚咕咚喝了几口泉水.... \n",
			   ({me}) );
		me->set("hit_points",me->query("max_hp"));
	}
	else return notify_fail("对不起, 只有等级小于5 的人才能在这喝水!!\n");
	return 1;
}

int look_at_clock()
{
        write( WEATHER_D->query_c_game_time()+"\n" );
        return 1 ;
}
