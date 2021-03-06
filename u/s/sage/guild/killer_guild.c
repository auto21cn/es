//sage修改于：98-4-19 8:21////#pragma save_binary

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
    set( "exits", ([
                  "north": "/u/s/sage/guild/gc",
                  "west" : "/d/killer/guild/killer_guild1",
                  "east" : "/u/s/sage/guild/killer_guild3",
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
        write("由于这段时间我没有时间，所以上面一片空白....。\n");
        return 1;
}
