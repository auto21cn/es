#include "hawk.h"
inherit ROOM;
void create()
{
        ::create();
        set_short("内城小径");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
行走在幽静怡人的内城小径，你可以察觉得到路边的植物也都有经过精心
照顾，环境有够好。三三两两的鸟人族小朋友在这边嘻闹，也为刚肃的天空之
城增添了一些活泼的气氛，顿时让你觉得远离喧嚣的感觉真好，有点乐不思蜀
的感觉。
LONG_DESCRIPTION
        );
        set( "objects", ([
                "boy1" : MOB"boy.c",
                "boy2" : MOB"boy.c",
                "girl" : MOB"girl.c",
                        ]) );

        set( "exits", ([
                "southwest" : HAWK"room2-4",
                "north" : HAWK"room2-7",
                        ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" || str =="north")
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(90);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}
