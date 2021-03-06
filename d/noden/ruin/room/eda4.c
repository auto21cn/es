// eda4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依达波第亚宫．觐见室");
    set_long(@C_LONG
这座宫殿虽然已经毁坏了，但觐见室里的王座 (throne) 却依然是完好如
初，一样地金碧辉煌。在你的左右方各有一道小门，应该是通往仆役休息室的
通道，南方的通道通向你刚才来的门厅。
C_LONG
    );
    set("item_desc", ([
        "throne" : "王座上雕刻著一只独眼怪 (ogre)，看起来很吓人。\n",
	"ogre" : "这独眼怪的眼睛似乎是某种按钮 (button)。\n"
        ]) );
    set("exits", ([ 
	"south" : AREA"eda3",
	"west" : AREA"eda5",
	"east" : AREA"eda6"
	 ]) );
    reset();
}

void init()
{
    add_action("to_push", "push");
}

int to_push(string s)
{
    object p;
    p = this_player();

    if (s == "button")
    {
 	write("你按了一下独眼怪的眼睛，但是它马上又弹了回来。\n\n");
        write("你忽然发现，独眼怪似乎正狠狠地瞪著你! 令你一阵晕眩!\n\n");
	p->set_temp("block_command", 1);
        call_out("recover", 15, p);
	return 1;
    }
    
    return notify_fail("你想按什麽?\n");
}

int recover(object p)
{
    p->set_temp("block_command", 0);
    tell_object(p, "当你回过神来时，你发现眼前的景物已经变了...\n");
    p->move(AREA"eda7");
    return 1;
}

