//traroom.c
#include "hawk.h"
inherit ROOM;
int potion;
int mirror;
void create()
{
        ::create();
        set_short("漂亮的房子");
        set_light(1);
        set_long( @LONG_DESCRIPTION
这是一栋装璜十分阔气的房子，看起来像是有钱人家住的地方。墙边摆了一
个大大的书柜(closet)，装了上百本的书，难道这房子的主人是一个饱读诗书的
读书人吗？
LONG_DESCRIPTION
        );
        set( "exits", ([
                "out" : HAWK"room2-11",
                     ]) );
        set( "objects", ([
                "traito" : MOB"traito",
               "servant" : MOB"servant"])
                        );
        set("c_item_desc",([
                "closet":"@@to_closet"
                        ]) );
        reset();
}//end of creat

string to_closet()
{
        return "这是一个很大的书柜，里面装了上百本的书，不过看起来书的後面\n"
                +"应该还有一些空间，不知道放了些什麽东西。\n\n";
}

void init()
{
        add_action("to_search","search");
}

int to_search(string str)
{
        object obj,obj2;
        if (!str) return 0;
        if (str == "box")
        {
                if (this_player()->query_temp("smore_box") != 1)
                {
                        tell_object(this_player(),"你找了又找，并没有发现任何东西。\n");
                        return 1;
                }

                if ( present("traito",this_object()) )
                {
                        tell_object(this_player(),"雷多瞪了你一眼。\n");
                        return 1;
                }
                else
                {
                        tell_object(this_player(),"你在雷多的铁箱子里找到一瓶橙色的药水。\n");
                        obj = new(OBJ"potion");
                        obj->move(this_object());
                        potion = 0;
			this_player()->set_explore("noden#42");
                        this_player()->set_temp("smore_box",2);
                        return 1;
                }
                return 1;
        }
        if (str == "closet")
        {
                if (mirror == 0) return 0;
                tell_object(this_player(),"你在书柜中找到一面镜子。\n");
                obj2 = new(OBJ"mirror");
                obj2->move(this_object());
                mirror = 0;
                return 1;
        }
        return 1;
}


void reset()
{
        ::reset();
        potion = 1;
        mirror = 1;
}
