#include "../story.h"

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name("wonderful straw","奇妙吸管");
        add( "id" , ({ "straw" }) );
        set_short( "奇妙吸管");
        set_long(@C_LONG
一根长长的的吸管，它的一头有个大圆球，圆球是中空的，或许，你可用它来摄取
(suck)某些动物死後□体里的液体。
C_LONG  );      
        set("unit","根");
        set("weight",10);
        set("no_sale",1);
        set("value", ({500, "silver"}) );
}
void init()
{
    add_action("do_suck","suck");
}
int do_suck(string arg)
{
    object player,env,target,liquid;
    string cname;
    if ( !arg ) return notify_fail("Syntax : <suck corpse>\n");
    player=this_player();
    env=environment(player);
    if (!target=present(arg,env)) 
       return notify_fail("这里没有那样东西。\n");
    cname=target->query("c_name");
    if( target->query("npc")!=SMOB"spider1" )
       return notify_fail("这个东西没有任何液体可供你摄取！\n");
    liquid=new(SITEM"liquid");
    liquid->move(env);   
    write(sprintf("你灵巧地从%s上取得一些液体！却不小心弄断了吸管，把液体洒在地上！\n",cname));
    target->remove();
    this_object()->remove();
    return 1;
}