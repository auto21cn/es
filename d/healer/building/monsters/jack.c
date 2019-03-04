#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 3 );
        set_name( "jack", "杰克" );
        set_short( "魔鬼杰克" );
        set( "gender", "male" );
        set( "race", "vampire" );
        set_natural_weapon( 4, 2, 2 );
        set_natural_armor( 30, 10 );
}


int accept_item(object who,object item)
{
     tell_room( environment(), 
            sprintf("杰克向%s(%s)点头微笑，说道: 谢谢！\n",
                who->query("c_name"),who->query("name") )
                ,who );
        tell_object( who,"杰克向你点头微笑，说道: 谢谢！\n");
                tell_object( who, 
                        "[你完成了 jack 任务，得到 1000 点经验]\n"
                        );
                who->gain_experience(8000);
}


