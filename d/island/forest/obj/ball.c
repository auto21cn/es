#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Spirit Ball","圣骑士元神");
    add("id",({"ball","spirit"}) );
    set_short("圣骑士元神");
    set_long(@LONG
这是圣骑士的元神，乍看之下，只是一颗小小的，亮亮的光球。
如果你能将它送回圣骑士的金身中，将会有不可思议的事情发生
哦！
LONG
            );
    set("unit","颗");
    set("weight",50);
    set("value",({1,"copper"}) );
    set("no_sale",1);
    set("ball",1);
 }
