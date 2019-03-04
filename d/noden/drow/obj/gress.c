#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("snake herb","蛇窝草");
    add("id",({"herb"}) );
    set_short("蛇窝草");
    set_long(
@C_LONG
    这是生长在蛇窝旁边的一种奇特小草，看起来有一点像韩国草，
据说在黑暗精灵族中，有人能将这种小草和某些药材混合，制成一种
药粉，洒在村落四周，能防止毒蛇的侵入。
C_LONG
            );
    set("unit","束");
    set("weight",18); 
    set("value", ({ 20, "silver" }));
    set( "no_sale",1); 
}    
