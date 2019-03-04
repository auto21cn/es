#include <mudlib.h>

inherit CONTAINER;

void create()
{
    ::create();
    set_name("Small Bag","历险小背包");
    add("id",({ "bag" }) );
    set_short("历险小背包");
    set_c_open_long("这是一般冒险家爱用的小背包，可用来装不少东西哦！\n");
    set("weight",10);
    set("weight_apply",60);
    set("max_load",200  );
    set("value",({100,"silver"}) );
    set("prevent_insert",1);
    set("prevent_put_money",1);
}
    