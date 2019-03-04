#include "../../story.h"

inherit OBJECT;

void create()
{
        set_name("dragon wood","遁龙桩");
        add( "id" , ({ "wood" }) );
        set_short( "遁龙桩");
        set_long(@C_LONG
这是一个外形很像龙的木头，另外在上面还画了很多咒语，那咒语的意思是
(use_dragon_wood)。
C_LONG  );      
        set("unit","个");
        set("weight",10);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_use","use_dragon_wood");
}
int do_use(string arg)
{
    object player,env;
    string name;
    player=this_player();
    env=environment(player);
    name=player->query("c_name");
    tell_room(env,sprintf(
      "%s祭起手中的遁龙桩，瞬间，一阵清风把%s刮起，旋即消失於空间！\n",name,name),player);
    tell_object(player,"你祭起手中的遁龙桩，忽然来了一阵清风把你刮来这里！\n");
    player->move_player(SCITY"house3","SNEAK");
    tell_room(environment(player),sprintf("一阵清风把%s刮来此地！\n",name),player);
    this_object()->remove();
    return 1;
}