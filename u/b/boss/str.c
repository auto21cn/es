#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("wine","力量之水");
        add( "id", ({ "wine" }) );
        set_short("力量之水");
        set( "weight", 10);
        set( "value", ({ 0, "coin" }));
        set("long", "一本能加力量的魔法书。\n");
        set("unit", "本");
        set("no_sale",1);
}

void init()
{
        add_action("to_drink","drink");
}

int to_drink(string arg)
{
        object me;
        int maxhp,maxsp,maxtp,maxfp;

        me = this_player();

        if( !arg || arg=="" || arg !="wine")
        {
                tell_object(this_player(),
                "你想干什么?\n"
                );
        }
        else 
        {
                tell_object(this_player(),
                "你感到全身都是力量。\n");
        
        tell_room( environment( me ),
                me->query("c_name")+"感到全身都是力量。\n"
                , me);
                
        me->set("gonfus_exp/bolo-fist",20000);
                        
        }
        return 1;
}
