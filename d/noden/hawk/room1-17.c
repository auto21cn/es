#include "hawk.h"
#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("光辉森林");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你走到森林的深处，环顾四周一片郁苍苍的树海围绕著你，你感受到一股生
生不息的活力从宇宙的各个角落传来，顿时间，你好像领略了什麽，但又说不出
是什麽。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southwest" : HAWK"room1-16",
                        ]) );
    reset();
}//end of creat

void init()
{
        mixed *condis;
        if( !(condis = this_player()->query( "conditions/_heal_sp" ))) return 0;
        HEAL_SP->apply_effect(this_player(),condis[0]-5,condis[1]);
        add_action( "remove_sp_recover", "go" );
        add_action( "do_cast", "cast");
        add_action( "remove_sp_recover", "sneak" );
        add_action( "see_mirror","see" );
}

int see_mirror(string str)
{
        if (!str || str != "mirror") return 0;
        write ("你发现你的镜子一片黑黝黝的，啥都看不到，大概是光被树林给档住了。\n");
        return 1;
}

int do_cast()
{
        write("\n\n一股神秘的力量阻止了你继续念咒。\n\n\n你的精神涣散了～～～～\n");
        this_player()->set("spell_points",10);
        return 1;
}

int remove_sp_recover(string str)
{
        mixed *condis;
        condis = this_player()->query( "conditions/_heal_sp" );
        if( !str || str == "southwest" )
        {
                HEAL_SP->apply_effect( this_player(), (condis[0]+5), condis[1] );
                return 0;
        }

        return 0;
}
