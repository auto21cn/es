#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("ghost-killed spell","灭魔符");
        add( "id" , ({ "spell" }) );
        set_short( "灭魔符");
        set_long(@C_LONG
上面写著一堆蝌蚪文，还有一行隶文，那隶文的意思是(spell_use)。
C_LONG  );      
        set("unit","张");
        set("weight",10);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_spell","spell_use");
}
int do_spell(string arg)
{
    object player,env;
    player=this_player();
    env=environment(player);
    tell_room(env,sprintf(
      "灭魔符自%s手中飞起，旋即消失於地上。\n",player->query("c_name")),player);
    tell_object(player,"\n灭魔符自你手中飞起，旋即消失於地上。\n\n");
    env->set("trap_set",1);
    this_object()->remove();
    return 1;
}