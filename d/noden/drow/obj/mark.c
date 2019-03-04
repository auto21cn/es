#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("captain's seal","侍卫队长徽章");
    add("id",({"seal"}));
    set_short("侍卫队长徽章");
    set_long(
@C_LONG
这是一枚侍卫队长的徽章，用铜片及碎宝石镶成，代表的是勇气与
无比的信心。
C_LONG
            );
    set("unit","枚");
    set("weight",20);
    set("value", ({ 100, "silver" }));
    set( "no_sale",1);
}                                 
