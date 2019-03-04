#include "../dony.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
        set_short( "east8", "阴暗的房间" );
	set_long(@C_LONG
你来到一个阴暗的房间,这里有一股□臭味,想必以前有很多人死在这儿。这里
没什麽摆设,只有一张手臂长宽的桌子,桌子上有一堆被嗑完的瓜子□, 还有一些空
酒瓶,想必是狱卒无聊的时候所遗留下来的垃圾。墙壁上有一根快要烧光的火把,不
知道为什麽,这里给你的感觉总是阴森森的。
C_LONG
	);
	set("light",0);
	set( "exits", ([
                      "west":DBEGGAR"jail1.c",
                      "south":DBEGGAR"east9.c"
	]) );
        set( "c_item_desc", ([
            "torch" :"一根快被烧完的火把。\n"
        ]) );        
        create_door( "west", "east", ([
                     "keyword" : ({ "copper door", "door" }),
                     "name" : "copper door",
                     "c_name" : "小铜门",
                     "c_desc" : "一扇很普通的小铜门",
                     "status" : "locked",
                     "lock" : "DBEGGAR_JAIL1" 
                    ]) );
     reset();
}

void init()
{ 
   add_action("do_touch","touch"); 
}

int do_touch( string arg )
{
     
     if ( !arg || arg != "torch" )
        return notify_fail("你要摸什麽?\n");
     
     tell_object( this_player(),
           "\n\n\n忽然间你觉得天旋地转地倒在地上.....\n\n\n\n\n");
     call_out( "recover",20,this_player());
     this_player()->set_temp("block_command",1);
     return 1;
}

void recover(object toucher)
{
   toucher->set_temp("block_command",0);
   tell_object(toucher,"\n\n你觉得你来到了一个奇怪的地方..。\n\n\n");
   this_player()->move_player(DBEGGAR"temp_room1");
}

