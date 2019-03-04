// tower0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔术师塔．入口");
    set_long(@C_LONG
这里是魔术师塔的入口，四周堆满著各种生物的骷髅，肃杀诡秘的气氛令
人毛骨悚然。魔术师塔的大门旁立著块石碑，上面写著：「路痴和菜鸟不准进
入」。
C_LONG
	    );

    set("exits", (["north" : AREA"tower1"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string arg)
{
    object p;
   
    p = this_player(); 
    write("你找呀找地，忽然地面上裂开了一个大洞 .... 哇～～～\n");
    p->move(AREA"tower2");
    p->receive_damage(5);
    return 1;
}

