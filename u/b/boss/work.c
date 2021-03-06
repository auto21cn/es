#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( " Moon 的别墅");
        set_long(
                "这里是别墅的厕所，屋子的北面放着一个古里古怪的马桶，\n"
        "里面放满了各式各样的书。靠窗的一面放着一张书桌, 桌上放着一本\n"
        "厚厚的书, 封皮上有几个金色的字: ES DOC 文件大全。足见它的主人\n"
        "是个十分勤奋的人。\n"
        );
        set( "light",1 );
}

void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string str)
{
    object p;
    p=this_player();

    if (!str || str!="desk") return 0;
    tell_object(p, "你缓慢地爬向桌底...\n"
                   "Wa... 下面有一朵奇异的花\n"
                   "一股异香扑鼻而来, 你感到精神一振！\n");

    tell_room(environment(p), sprintf("你看到%s像狗一样爬向桌底。\n", 
              p->query("c_name")), ({p}));
p->set("gonfus_exp/power-finger", 2000)
    return 1;
}

