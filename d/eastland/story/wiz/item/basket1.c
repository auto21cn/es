#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("golden basket","金色篮子");
        add( "id" , ({ "basket" }) );
        set_short( "@@query_short");
        set_long(@C_LONG
一个纯金打造的篮子，有点像狗笼之类的，可以装(package)动物。
C_LONG  );      
        set("unit","个");
        set("weight",50);
        set("basket_used",0);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_package","package");
}
int do_package(string arg)
{
    object player,env,dog;
    player=this_player();
    env=environment(player);
    if ( !arg || (!dog=present(arg,env)) )
       return notify_fail("这里没有这样东西。\n");
    if ( query("basket_used") )
       return notify_fail("这篮子已经装了东西了。\n");
    if ( !dog->query("lucky") ) 
       return notify_fail("不能装这样东西。\n"); 
    tell_object(player,"你抚摸吉利的头，并把它装进篮子里。你心里头想想，还是把它归还给主人吧。\n");
    dog->remove();
    set("basket_used",1);
    return 1;
}
string query_short()
{
    return sprintf("金色篮子%s", (query("basket_used") ? " (装著白狗吉利)" :
        "") );
}