#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 3 );
        set_name( "smith", "铁匠" );
        set_short( "老铁匠" );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set_natural_weapon( 4, 2, 2 );
        set_natural_armor( 30, 10 );
}


int accept_item(object who,object item)
{
     tell_room( environment(), 
            sprintf("老铁匠向%s(%s)点头微笑，说道: 谢谢！\n",
                who->query("c_name"),who->query("name") )
                ,who );
        tell_object( who,"老铁匠向你点头微笑，说道: 谢谢！\n");
                tell_object( who, 
                        "[你完成了 Smith 任务，得到 1000 点经验]\n"
                        );
                who->gain_experience(10000);
                }


