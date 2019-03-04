//sage修改于：98-6-12 ////#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <org.h>
#include "../killer.h"

#define BOARD KILLER"killer_board"

inherit NEW_GUILD;
inherit DOORS;
void create()
{
    object guild_master;

        ::create();

    set_short("杀手公会");
        set_long(
                 @C_LONG_DESCRIPTION
    你进了一间乌灯黑火的房间，一阵寒风吹来，不觉打了个哆嗦，你的第六
感告诉你，在房子的某个角落，正有一双狼一样的眼睛在盯着你，只要你一放
松警戒，这双眼睛就会向你扑来。然而在这间房子里，却看不到半个人影。
    一本书悬挂在房子的正中间。
    在角落里有一张已经发霉的纸(paper)，你用尽所有精力，才依稀看出一点
眉目。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "paper" : @LONG_TEXT
———————————————————————————————————
破纸上写著:
    本公会为世上最强之公会，加入后能学到世上无双的武功，可以称霸世界，
名额有限，欲入从速。
    
    详细入会情形请用 help guild 阅读说明。
———————————————————————————————————
LONG_TEXT
,
                 "book":"这是一本关于杀手公会限制与情形的书。你可以read它。\n"
 ]) );
    set("exit_suppress",({"east"}));
    set( "exits", ([
                  "north": "/u/s/sage/guild/gc",
                  "west" : "/d/killer/guild/killer_guild1",
                  "east" : "/d/killer/guild/killer_guild3",
        ]) );


        set( "pre_exit_func", ([
                "west" : "check_killer" ]) );
    guild_master=new("/d/killer/monster/blowblood");
    guild_master->move(this_object());
       create_door("north", "south", ([
                    "keyword"       : ({ "tree door", "door" }),
                    "name"          : "tree door",
                    "c_name"        : "木门",
                    "c_desc"        : "一扇破烂的木门",
                    "status"        : "closed",
        ]) );

        set_guild("killer");
        BOARD->frog();
        reset();
}
void init()
{
        ::init();
        add_action( "do_read", "read" );
}
int do_read(string arg)
{
        if( !arg || arg!="book" ) return 0;
        write("    杀手是本世纪头号敌人，全世界的英雄无时无刻都想杀之而后快，但他们\n"
              "    实在是太厉害，杀手拥有超强的战斗力，他们对每重生物的生理构造都十\n"
              "    分清楚，所以能给对手一击致命的伤害，他们在战斗中不会考虑自己的安\n"
              "    全，直到把对手杀死为止。当他们完成一个任务，或者杀死一个敌人，都\n"
              "    会拿到任务点，任务点越高，他就越会有机会成为公会中的领导人物。\n\n"
              "    杀手视杀手公会为家，只要有人对公会做出一些他们认为对他们名誉、安\n"
              "    全有影响的事，他们就会全力反击，直到肇事者消失为止。\n\n\n"
              );
      return 1;
}
