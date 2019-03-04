#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Seed of Luoko","龙皇的种子");
    add("id",({"seed"}) );
    set_short("种子");
    set_long(@LONG
这是龙皇的种子，一副圆滚滚，亮晶晶的模样，真没想到这竟会是守护灵！
还是赶快想办法将它种到御花园去吧，免得乾掉了！
LONG
             );
    set("unit","颗");
    set("weight",5);
    set("value",({5,"copper"}) );
    set("no_sale",1);
    set("luoko_seed",1);
}

    